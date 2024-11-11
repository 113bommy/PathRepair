#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
int tax[N], rk[N], tp[N], sa[N], height[N];
string s;
stack<pair<long long, long long> > stk;
bool cmp(int* r, int a, int b, int k) {
  return r[a] == r[b] && r[a + k] == r[b + k];
}
void radix_sort() {
  for (int i = 0; i <= m; i++) tax[i] = 0;
  for (int i = 1; i <= n; i++) tax[rk[tp[i]]]++;
  for (int i = 1; i <= m; i++) tax[i] += tax[i - 1];
  for (int i = n; i >= 1; i--) sa[tax[rk[tp[i]]]--] = tp[i];
}
void get_sa() {
  for (int i = 1; i <= n; i++) {
    rk[i] = s[i];
    tp[i] = i;
    m = max(m, (int)s[i]);
  }
  radix_sort();
  for (int j = 1, p = 0; p < n; j <<= 1, m = p) {
    p = 0;
    for (int i = n - j + 1; i <= n; i++) tp[++p] = i;
    for (int i = 1; i <= n; i++) {
      if (sa[i] > j) tp[++p] = sa[i] - j;
    }
    radix_sort();
    swap(rk, tp);
    rk[sa[1]] = p = 1;
    for (int i = 2; i <= n; i++) {
      rk[sa[i]] = cmp(tp, sa[i], sa[i - 1], j) ? p : ++p;
    }
  }
}
void get_height() {
  for (int i = 1, k = 0; i <= n; ++i) {
    if (k) --k;
    while (s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
    height[rk[i]] = k;
  }
}
int main() {
  cin >> s;
  n = s.size();
  s = "#" + s;
  get_sa();
  get_height();
  long long cnt = 0;
  long long ans = n * (n + 1) / 2;
  for (int i = n; i >= 2; i--) {
    pair<long long, long long> t = {height[i], 1};
    while (stk.size() && stk.top().first > t.first) {
      cnt -= stk.top().first * stk.top().second;
      t.second += stk.top().second;
      stk.pop();
    }
    cnt += t.first * t.second;
    stk.push(t);
    ans += cnt;
  }
  cout << ans << endl;
  return 0;
}
