#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int n, a[N], suf[N], nsuf[N], c[N], nc[N], col, sum[N], rmq[20][N], lg[N],
    lcp[N], pos[N], head[N];
long long ans;
vector<int> p[N + N];
char second[N];
bool cmp(int i, int j) { return second[i] < second[j]; }
void SA() {
  second[++n] = '#';
  for (int i = 1; i <= n; i++) suf[i] = i;
  sort(suf + 1, suf + n + 1, &cmp);
  col = 0;
  for (int i = 1; i <= n; i++) {
    if (i == 1 || second[suf[i]] != second[suf[i - 1]]) {
      col++;
      head[col] = i;
      c[suf[i]] = col;
    } else
      c[suf[i]] = c[suf[i - 1]];
  }
  for (int len = 1; len <= n; len += len) {
    for (int i = 1; i <= n; i++) {
      int j = suf[i] - len;
      if (j < 1) j += n;
      nsuf[head[c[j]]++] = j;
    }
    col = 0;
    for (int i = 1; i <= n; i++) {
      suf[i] = nsuf[i];
      int a = suf[i] + len;
      if (a > n) a -= n;
      int b = suf[i - 1] + len;
      if (b > n) b -= n;
      if (i == 1 || c[suf[i]] != c[suf[i - 1]] || c[a] != c[b]) {
        col++;
        head[col] = i;
        nc[suf[i]] = col;
      } else
        nc[suf[i]] = nc[suf[i - 1]];
    }
    for (int i = 1; i <= n; i++) c[i] = nc[i];
  }
  n--;
  for (int i = 1; i <= n; i++) {
    suf[i] = suf[i + 1];
    pos[suf[i]] = i;
  }
  int L = 0;
  for (int i = 1; i <= n; i++) {
    int j = pos[i];
    if (j == n) {
      L = lcp[j] = 0;
      continue;
    }
    if (L) L--;
    while (i + L <= n && suf[j + 1] + L <= n &&
           second[i + L] == second[suf[j + 1] + L])
      L++;
    lcp[j] = L;
  }
}
int get_min(int l, int r) {
  if (l > r) return 0;
  int k = lg[r - l + 1];
  return min(rmq[k][l], rmq[k][r - (1 << k) + 1]);
}
int get(int l, int r, int x) {
  if (l > r) return 0;
  x += n;
  return upper_bound(p[x].begin(), p[x].end(), r) -
         lower_bound(p[x].begin(), p[x].end(), l);
}
int calc(int start, int l) {
  int r = -1;
  int L = start, R = n;
  while (L <= R) {
    int mid = (L + R) / 2;
    if (get_min(start, mid) >= sum[start - 1]) {
      r = mid;
      L = mid + 1;
    } else
      R = mid - 1;
  }
  if (r == -1) return 0;
  return get(l, r, sum[start - 1]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> second[i];
    sum[i] = sum[i - 1] + (second[i] == '(' ? 1 : -1);
    p[sum[i] + n].push_back(i);
    rmq[0][i] = sum[i];
    if (i > 1) lg[i] = lg[i / 2] + 1;
  }
  for (int i = 1; i < 20; i++)
    for (int j = 1; j <= n; j++)
      rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
  SA();
  for (int i = 1; i <= n; i++) ans += calc(suf[i], suf[i] + lcp[i - 1]);
  cout << ans;
  return 0;
}
