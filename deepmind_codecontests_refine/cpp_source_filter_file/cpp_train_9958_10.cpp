#include <bits/stdc++.h>
using namespace std;
const long long int P = 1000000000 + 7;
long long int MOD(long long int a, long long int b) {
  if (a > b)
    return a - b;
  else
    return b - a;
}
long long int max3(long long int a, long long int b, long long int c) {
  return max(c, max(a, b));
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int Pow(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long int logg(long long int a) {
  long long int x = 0;
  while (a > 1) {
    x++;
    a /= 2;
  }
  return x;
}
long long int mins(long long int a, long long int b) {
  if (a < b) {
    return a;
  }
  return b;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
string conbin(int a, int size) {
  string g;
  while (a > 0) {
    g.push_back(a % 2);
    a = a / 2;
  }
  while (g.size() < size) {
    g.push_back('0');
  }
  reverse(g.begin(), g.end());
  return g;
}
struct comp_pair_int {
  bool operator()(const pair<int, int> &a, const int &b) {
    return (a.first < b);
  }
  bool operator()(const int &a, const pair<int, int> &b) {
    return (a < b.first);
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, m;
  cin >> n >> m;
  vector<long long int> x(n), y(m);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> y[i];
  }
  for (int i = 1; i < n; i++) {
    x[i] = x[i - 1] + x[i];
  }
  for (int i = 0; i < m; i++) {
    y[i] = y[i - 1] + y[i];
  }
  int i = 0;
  int j = 0;
  int ans = 0;
  while (i < n && j < m) {
    while (y[j] < x[i]) {
      j++;
    }
    if (x[i] == y[j]) {
      ans++;
    }
    if (i == n - 1 && j == m - 1) {
      break;
    }
    i++;
  }
  cout << ans;
}
