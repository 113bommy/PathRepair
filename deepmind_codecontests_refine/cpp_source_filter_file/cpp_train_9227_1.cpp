#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long a, long long p) { return power(a, p - 2, p); }
long long n, x1, x2;
void go(vector<pair<long long, long long> > &a, bool d) {
  long long sum = 0;
  long long mini = 1e10;
  long long first = -1;
  long long second = -1;
  vector<long long> v1, v2;
  for (long long i = 0; i < n; i++) {
    sum += a[i].first;
    mini = min(mini, a[i].first);
    if (first == -1)
      v1.push_back(i);
    else
      v2.push_back(i);
    if (first == -1 && sum > x1 && x1 <= (mini * (i + 1))) {
      first = i;
      mini = 1e10;
      sum = 0;
      continue;
    }
    if (first != -1 && sum > x2 && x2 <= (mini * (i - first))) {
      second = i;
      break;
    }
  }
  if (d) swap(v1, v2);
  if (second == -1) return;
  cout << "Yes" << endl;
  cout << v1.size() << " " << v2.size() << endl;
  for (auto p : v1) cout << a[p].second << " ";
  cout << endl;
  for (auto p : v2) cout << a[p].second << " ";
  cout << endl;
  exit(0);
}
int main() {
  scanf("%lld %lld %lld", &(n), &(x1), &(x2));
  vector<pair<long long, long long> > a;
  for (long long i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    a.push_back({x, i + 1});
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  go(a, false);
  swap(x1, x2);
  go(a, true);
  cout << "No" << endl;
}
