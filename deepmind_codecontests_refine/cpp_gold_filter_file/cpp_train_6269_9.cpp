#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long int gcd(long long int a, long long int b) {
  while (b) {
    long long int x = a % b;
    a = b;
    b = x;
  }
  return a;
}
long long int lcm(long long int a, long long int b) {
  return a / gcd(a, b) * b;
}
unsigned long long int binpow(long long int base, long long int exp) {
  long long int res = 1;
  while (1) {
    if (exp & 1) res *= base;
    exp >>= 1;
    if (!exp) break;
    base *= base;
  }
  return res;
}
int n, m;
vector<int> v[105];
int main() {
  int i, j, k, t, cs = 0, ck = 0;
  int a, b, c, d, e, f;
  long long int sum = 0, cnt = 0;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> j >> k;
    v[j].push_back(k);
    v[k].push_back(j);
  }
  ck = 1;
  cs = 1;
  for (i = 0; i < n; i++) {
    if (v[i].size() != 1) cs = 0;
  }
  if (cs) {
    cout << 0 << "\n";
    return 0;
  }
  while (ck) {
    ck = 0;
    stack<pair<int, int> > stk;
    for (i = 1; i <= n; i++) {
      if (v[i].size() == 1) {
        stk.push(make_pair(i, v[i][0]));
        v[i].clear();
        ck = 1;
      }
    }
    while (!stk.empty()) {
      pair<int, int> p = stk.top();
      stk.pop();
      k = p.second;
      i = p.first;
      auto it = find(v[k].begin(), v[k].end(), i);
      if (it != v[k].end()) {
        v[k].erase(it);
        ck = 1;
      }
    }
    if (ck) cnt++;
  }
  cout << cnt << "\n";
  return 0;
}
