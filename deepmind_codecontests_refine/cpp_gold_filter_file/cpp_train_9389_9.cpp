#include <bits/stdc++.h>
using namespace std;
const int N = 3 * (2e5 + 5);
int wa[N], wb[N], wss[N], wv[N], sa[N];
int rak[N], height[N], cal[N], n;
char s[N], ans[N], s1[N];
int cnt[N], l[N], r[N];
int c0(int *r, int a, int b) {
  return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];
}
int c12(int k, int *r, int a, int b) {
  if (k == 2) return r[a] < r[b] || r[a] == r[b] && c12(1, r, a + 1, b + 1);
  return r[a] < r[b] || r[a] == r[b] && wv[a + 1] < wv[b + 1];
}
void Rsort(int *r, int *a, int *b, int n, int m) {
  for (int i = 0; i < n; i++) wv[i] = r[a[i]];
  for (int i = 0; i < m; i++) wss[i] = 0;
  for (int i = 0; i < n; i++) wss[wv[i]]++;
  for (int i = 1; i < m; i++) wss[i] += wss[i - 1];
  for (int i = n - 1; i >= 0; i--) b[--wss[wv[i]]] = a[i];
}
void dc3(int *r, int *sa, int n, int m) {
  int i, j, *rn = r + n, *san = sa + n, ta = 0, tb = (n + 1) / 3, tbc = 0, p;
  r[n] = r[n + 1] = 0;
  for (i = 0; i < n; i++)
    if (i % 3 != 0) wa[tbc++] = i;
  Rsort(r + 2, wa, wb, tbc, m);
  Rsort(r + 1, wb, wa, tbc, m);
  Rsort(r, wa, wb, tbc, m);
  for (p = 1, rn[((wb[0]) / 3 + ((wb[0]) % 3 == 1 ? 0 : tb))] = 0, i = 1;
       i < tbc; i++)
    rn[((wb[i]) / 3 + ((wb[i]) % 3 == 1 ? 0 : tb))] =
        c0(r, wb[i - 1], wb[i]) ? p - 1 : p++;
  if (p < tbc)
    dc3(rn, san, tbc, p);
  else
    for (i = 0; i < tbc; i++) san[rn[i]] = i;
  for (i = 0; i < tbc; i++)
    if (san[i] < tb) wb[ta++] = san[i] * 3;
  if (n % 3 == 1) wb[ta++] = n - 1;
  Rsort(r, wb, wa, ta, m);
  for (i = 0; i < tbc; i++)
    wv[wb[i] = ((san[i]) < tb ? (san[i]) * 3 + 1 : ((san[i]) - tb) * 3 + 2)] =
        i;
  for (i = 0, j = 0, p = 0; i < ta && j < tbc; p++)
    sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
  for (; i < ta; p++) sa[p] = wa[i++];
  for (; j < tbc; p++) sa[p] = wb[j++];
}
void calheight(int *r, int *sa, int n) {
  int i, j, k = 0;
  for (i = 1; i <= n; i++) rak[sa[i]] = i;
  for (i = 0; i < n; height[rak[i++]] = k)
    for (k ? k-- : 0, j = sa[rak[i] - 1]; r[i + k] == r[j + k]; k++)
      ;
  for (int i = n; i; i--) rak[i] = rak[i - 1];
  for (int i = n; i; i--) sa[i]++;
}
void gao() {
  stack<int> temp1, temp2;
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      temp1.push(i);
      l[i] = i;
    } else {
      while (height[temp1.top()] >= height[i]) {
        temp1.pop();
        if (temp1.empty()) break;
      }
      if (!temp1.empty())
        l[i] = temp1.top() + 1;
      else
        l[i] = 1;
      temp1.push(i);
    }
  }
  for (int i = n; i >= 1; i--) {
    if (i == n) {
      temp2.push(i);
      r[i] = i;
    } else {
      while (height[temp2.top()] >= height[i]) {
        temp2.pop();
        if (temp2.empty()) break;
      }
      if (!temp2.empty())
        r[i] = temp2.top() - 1;
      else
        r[i] = n;
      temp2.push(i);
    }
  }
}
long long a[N];
unordered_map<int, int> mp[N];
int main() {
  int t, cas = 1, k;
  scanf("%s", s + 1);
  n = strlen(s + 1);
  cal[n + 1] = 0;
  for (int i = 1; i <= n; i++) cal[i] = s[i] - 'a' + 1;
  dc3(cal + 1, sa, n + 1, 30);
  calheight(cal + 1, sa, n);
  gao();
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (height[i] == 0) {
      ans += n - sa[i] + 1 - max(height[i + 1], height[i]);
    } else {
      if (!mp[l[i]][r[i]]) {
        ans += 1ll * (r[i] - l[i] + 2) * (r[i] - l[i] + 3) / 2 *
               (height[i] - max(height[l[i] - 1], height[r[i] + 1]));
        mp[l[i]][r[i]] = 1;
      }
      ans += n - sa[i] + 1 - max(height[i + 1], height[i]);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
