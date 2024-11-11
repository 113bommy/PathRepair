#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1, -1, 1, 1, -1};
int dy[] = {1, 0, -1, 0, -1, -1, 1, 1};
int kx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int ky[] = {-1, 1, 2, 2, 1, -1, -2, -2};
inline long long gcd(long long a, long long b) {
  a = fabs(a);
  b = fabs(b);
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
inline long long bigmod(long long a, long long p, long long m) {
  long long res = 1 % m, x = a % m;
  while (p) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}
struct DATA {
  long long a, b;
};
vector<DATA> arr;
set<long long> s;
int main() {
  long long n;
  scanf("%lld", &n);
  for (int i = (int)(1); i <= (int)(n); i++) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    arr.push_back({x, y});
  }
  if (n == 1) {
    cout << arr[0].a << endl;
    exit(0);
  }
  for (int i = 2; i * i <= arr[0].a; i++) {
    if (arr[0].a % i == 0) {
      while (arr[0].a % i == 0) arr[0].a /= i;
      s.insert(i);
      s.insert(arr[0].a / i);
    }
  }
  if (arr[0].a > 2) s.insert(arr[0].a);
  for (int i = 2; i * i <= arr[0].b; i++) {
    if (arr[0].b % i == 0) {
      while (arr[0].b % i == 0) arr[0].b /= i;
      s.insert(i);
      s.insert(arr[0].b / i);
    }
  }
  if (arr[0].b > 2) s.insert(arr[0].b);
  for (set<long long>::iterator it = s.begin(); it != s.end(); it++) {
    bool found = 1;
    long long x = *it;
    if (x == 0) continue;
    for (int j = (int)(1); j <= (int)(arr.size() - 1); j++) {
      long long val1 = arr[j].a;
      long long val2 = arr[j].b;
      if (val1 % x != 0 and val2 % x != 0) {
        found = 0;
        break;
      }
    }
    if (found and x > 1) {
      cout << x << endl;
      exit(0);
    }
  }
  cout << "-1" << endl;
  return 0;
}
