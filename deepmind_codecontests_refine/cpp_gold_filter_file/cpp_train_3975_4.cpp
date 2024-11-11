#include <bits/stdc++.h>
using namespace std;
long long a[55], b[55];
int c[55], n, m, k, cc[55];
pair<int, int> p[55];
vector<long long> vec[55];
int tt[2][55][55][102];
long long mem[51][51][51][101];
bool vis[51][51][51][101];
long long dp(int pos, int cnt, int lst, int indx) {
  if (pos == m) {
    if (cnt == n)
      return 0;
    else
      return -1000000000000000002ll;
  }
  if (vis[pos][cnt][lst][indx]) return mem[pos][cnt][lst][indx];
  vis[pos][cnt][lst][indx] = 1;
  long long ret = dp(pos + 1, cnt, lst, indx);
  if (cc[lst] < cc[pos] && tt[0][lst][pos][indx] != -1)
    ret = max(ret, vec[pos][tt[0][lst][pos][indx]] +
                       dp(pos + 1, cnt + 1, pos, tt[0][lst][pos][indx]));
  if (cc[lst] < cc[pos] && tt[1][lst][pos][indx] != -1)
    ret = max(ret, vec[pos][tt[1][lst][pos][indx]] +
                       dp(pos + 1, cnt + 1, pos, tt[1][lst][pos][indx]));
  return mem[pos][cnt][lst][indx] = ret;
}
void path(int pos, int cnt, int lst, int indx) {
  if (pos == m) return;
  if (dp(pos + 1, cnt, lst, indx) == mem[pos][cnt][lst][indx]) {
    path(pos + 1, cnt, lst, indx);
    return;
  }
  if (cc[lst] < cc[pos] && tt[0][lst][pos][indx] != -1 &&
      vec[pos][tt[0][lst][pos][indx]] +
              dp(pos + 1, cnt + 1, pos, tt[0][lst][pos][indx]) ==
          mem[pos][cnt][lst][indx]) {
    printf("%d %lld\n", p[pos].second + 1, vec[pos][tt[0][lst][pos][indx]]);
    path(pos + 1, cnt + 1, pos, tt[0][lst][pos][indx]);
    return;
  }
  if (cc[lst] < cc[pos] && tt[1][lst][pos][indx] != -1 &&
      vec[pos][tt[1][lst][pos][indx]] +
              dp(pos + 1, cnt + 1, pos, tt[1][lst][pos][indx]) ==
          mem[pos][cnt][lst][indx]) {
    printf("%d %lld\n", p[pos].second + 1, vec[pos][tt[1][lst][pos][indx]]);
    path(pos + 1, cnt + 1, pos, tt[1][lst][pos][indx]);
    return;
  }
  return;
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; i++)
    scanf("%lld %lld %d", &a[i], &b[i], &c[i]), p[i] = {c[i], i};
  sort(p, p + m);
  for (int i = 0; i < m; i++) {
    int x = p[i].second;
    cc[i] = c[x];
    for (long long j = a[x]; j <= b[x]; j++) vec[i].push_back(j);
    sort(vec[i].begin(), vec[i].end());
  }
  for (int i = m - 2; i >= 0; i--)
    for (int j = 0; j < vec[i].size(); j++)
      for (int l = i + 1; l < m; l++) {
        long long x = vec[i][j] + k;
        tt[0][i][l][j] = tt[1][i][l][j] = -1;
        if (x >= vec[l][0] && x <= vec[l].back()) {
          int r = lower_bound(vec[l].begin(), vec[l].end(), x) - vec[l].begin();
          if (vec[l][r] == x) tt[0][i][l][j] = r;
        }
        x = vec[i][j] * k;
        if (x >= vec[l][0] && x <= vec[l].back()) {
          int r = lower_bound(vec[l].begin(), vec[l].end(), x) - vec[l].begin();
          if (vec[l][r] == x) tt[1][i][l][j] = r;
        }
      }
  long long res = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < vec[i].size(); j++)
      res = max(res, vec[i][j] + dp(i + 1, 1, i, j));
  if (res == 0)
    printf("NO\n");
  else {
    printf("YES\n");
    for (int i = 0; i < m; i++)
      for (int j = 0; j < vec[i].size(); j++)
        if (vec[i][j] + dp(i + 1, 1, i, j) == res) {
          printf("%d %lld\n", p[i].second + 1, vec[i][j]);
          path(i + 1, 1, i, j);
          return 0;
        }
  }
  return 0;
}
