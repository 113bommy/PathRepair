#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e1 + 17;
int n, m, ax[maxn], ay[maxn], bx[maxn], by[maxn], cnt[maxn], mp[maxn][maxn],
    mpd[maxn][maxn];
stringstream out;
void move(int id, int dx, int dy, int t = 0) {
  mp[ax[id]][ay[id]] = 0;
  mp[dx][dy] = id;
  auto fixx = [&]() {
    while (ax[id] > dx) {
      out << ax[id] << ' ' << ay[id] << ' ' << ax[id] - 1 << ' ' << ay[id]
          << '\n';
      ax[id]--;
    }
    while (ax[id] < dx) {
      out << ax[id] << ' ' << ay[id] << ' ' << ax[id] + 1 << ' ' << ay[id]
          << '\n';
      ax[id]++;
    }
  };
  auto fixy = [&]() {
    while (ay[id] > dy) {
      out << ax[id] << ' ' << ay[id] << ' ' << ax[id] << ' ' << ay[id] - 1
          << '\n';
      ay[id]--;
    }
    while (ay[id] < dy) {
      out << ax[id] << ' ' << ay[id] << ' ' << ax[id] << ' ' << ay[id] + 1
          << '\n';
      ay[id]++;
    }
  };
  if (t == 0) {
    fixx();
    fixy();
  } else if (t == 1) {
    if (dy < ay[id])
      move(id, ax[id], dy + 1);
    else
      move(id, ax[id], dy - 1);
    move(id, dx, dy);
  } else {
    fixy();
    fixx();
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> ax[i] >> ay[i];
    mp[ax[i]][ay[i]] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> bx[i] >> by[i];
    cnt[by[i]]++;
    mpd[bx[i]][by[i]] = i;
  }
  int cl;
  for (int i = 1; i <= n; i++)
    if (cnt[i] <= 1) cl = i;
  int cnt = 0;
  for (int i = cl; i <= n; i++) {
    for (int j = cnt + 1; j <= n; j++)
      if (mp[j][i]) move(mp[j][i], ++cnt, cl);
    if (i != cl)
      for (int j = cnt; j >= 1; j--)
        if (mp[j][i]) move(mp[j][i], ++cnt, cl);
  }
  for (int i = cl - 1; i >= 1; i--) {
    for (int j = cnt + 1; j <= n; j++)
      if (mp[j][i]) move(mp[j][i], ++cnt, cl);
    for (int j = cnt; j >= 1; j--)
      if (mp[j][i]) move(mp[j][i], ++cnt, cl);
  }
  for (int i = 1; i < cl - 1; i++) {
    for (int j = n; j >= 1; j--)
      if (mpd[j][i]) move(mpd[j][i], j, i, 1);
  }
  for (int i = n; i >= cl + 2; i--) {
    for (int j = n; j >= 1; j--)
      if (mpd[j][i]) move(mp[++cnt][cl], j, i, 1);
  }
  for (int i = 1; i <= n; i++)
    if (mp[i][cl]) move(mp[i][cl], i, by[mp[i][cl]], 2);
  for (int i = 1; i <= n; i++)
    if (mp[i][cl]) move(mp[i][cl], 1, cl);
  auto rep = [&](int j) {
    int ta = n, rem = 0;
    for (int i = n; i >= 1; i--)
      if (mp[i][j]) {
        rem++;
        move(mp[i][j], ta--, j);
      }
    ta = n;
    while (rem--) {
      int cer = -1;
      for (int i = 1; i <= n; i++)
        if (mp[i][j] && (cer == -1 || bx[mp[i][j]] > bx[cer])) cer = mp[i][j];
      int wx = ax[cer];
      move(cer, ta--, cl, 2);
      while (wx < n && mp[wx + 1][j]) move(mp[wx + 1][j], wx, j), wx++;
    }
    for (int i = 1; i <= n; i++)
      if (mp[i][cl] && by[mp[i][cl]] != cl)
        move(mp[i][cl], bx[mp[i][cl]], by[mp[i][cl]], 2);
  };
  if (cl > 1) rep(cl - 1);
  if (cl < n) rep(cl + 1);
  for (int i = 1; i <= n; i++)
    if (mp[i][cl]) move(mp[i][cl], bx[mp[i][cl]], by[mp[i][cl]]);
  string ans = out.str();
  assert(count(ans.begin(), ans.end(), '\n') <= 10800);
  cout << count(ans.begin(), ans.end(), '\n') << '\n' << ans;
}
