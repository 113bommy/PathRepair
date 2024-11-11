#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4;
string s1, s2, s;
int n, m;
int x[maxn], y[maxn], c[maxn], sa[maxn];
int height[maxn], rk[maxn];
void SA() {
  for (int i = 1; i <= n; i++) {
    x[i] = s[i];
    c[x[i]]++;
  }
  for (int i = 2; i <= m; i++) c[i] += c[i - 1];
  for (int i = n; i >= 1; i--) sa[c[x[i]]--] = i;
  for (int k = 1; k <= n; k = k << 1) {
    int num = 0;
    for (int i = n - k + 1; i <= n; ++i) y[++num] = i;
    for (int i = 1; i <= n; i++) {
      if (sa[i] > k) y[++num] = sa[i] - k;
    }
    for (int i = 1; i <= m; i++) c[i] = 0;
    for (int i = 1; i <= n; i++) c[x[i]]++;
    for (int i = 2; i <= m; i++) c[i] += c[i - 1];
    for (int i = n; i >= 1; i--) {
      sa[c[x[y[i]]]] = y[i];
      c[x[y[i]]]--;
      y[i] = 0;
    }
    swap(x, y);
    num = 1;
    x[sa[1]] = 1;
    for (int i = 2; i <= n; i++) {
      if (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k])
        x[sa[i]] = num;
      else
        x[sa[i]] = (++num);
    }
    if (num == n) break;
    m = num;
  }
}
void Height() {
  int k = 0;
  for (int i = 1; i <= n; i++) rk[sa[i]] = i;
  for (int i = 1; i <= n; i++) {
    if (rk[i] == 1) continue;
    if (k) k--;
    int j = sa[rk[i] - 1];
    while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
    height[rk[i]] = k;
  }
}
bool check(int k) {
  int cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n; i++) {
    if (height[i] < k) {
      if (cnt1 == 1 && cnt2 == 1) return true;
      cnt1 = cnt2 = 0;
      if (sa[i] <= s1.length())
        cnt1++;
      else if (sa[i] >= s1.length())
        cnt2++;
      continue;
    }
    if (sa[i] <= s1.length())
      cnt1++;
    else if (sa[i] >= s1.length())
      cnt2++;
  }
  return cnt1 == 1 && cnt2 == 1;
}
int main() {
  cin >> s1 >> s2;
  s = s1 + "#" + s2;
  n = s.length();
  s = " " + s;
  m = 122;
  SA();
  Height();
  int ans = -1;
  for (int i = 1; i <= s1.length(); i++) {
    if (check(i)) {
      ans = i;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}
