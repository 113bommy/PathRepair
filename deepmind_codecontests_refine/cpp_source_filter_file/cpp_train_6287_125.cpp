#include <bits/stdc++.h>
using namespace std;
int a[1700][1700];
int b[100][100];
int k;
vector<pair<int, int> > w;
vector<int> t;
vector<int> ans;
void dfs(int x, int y, int k) {
  if (a[x][y] != 1) {
    return;
  }
  a[x][y] = k;
  dfs(x + 1, y, k);
  dfs(x - 1, y, k);
  dfs(x, y + 1, k);
  dfs(x, y - 1, k);
}
void dfs2(int x, int y, int k, int r) {
  if (a[x][y] != k || r < 0) {
    return;
  }
  a[x][y] = -k;
  dfs2(x + 1, y, k, r - 1);
  dfs2(x - 1, y, k, r - 1);
  dfs2(x, y + 1, k, r - 1);
  dfs2(x, y - 1, k, r - 1);
}
void g(int i, int j) {
  if (a[i][j] < 0) {
    t[-a[i][j]] += -100000;
    return;
  }
  if (a[i][j] != 0) {
    t[a[i][j]]++;
  }
}
void u(int i, int j) {
  if (a[i][j] < 0) {
    t[-a[i][j]] -= -100000;
    return;
  }
  if (a[i][j] != 0) {
    t[a[i][j]]--;
  }
}
int test(int x, int y, int h) {
  int mx = 1;
  for (int i = 0; i < (int)t.size(); i++) {
    if (t[i] > t[mx]) {
      mx = i;
    }
  }
  int s = t[mx];
  if (s < h * h * 0.35) {
    return -1;
  }
  int l1 = 0, l2 = 0, l3 = 0, l4 = 0;
  for (int i = 0; i < h - 1; i++) {
    if (a[x + i][y] == mx) l1++;
    if (a[x][y + i] == mx) l4++;
    if (a[x + i][y + h - 1] == mx) l3++;
    if (a[x + h - 1][y + i] == mx) l2++;
  }
  int l = l1 + l2 + l3 + l4;
  vector<int> v;
  v.push_back(l1);
  v.push_back(l2);
  v.push_back(l3);
  v.push_back(l4);
  sort(v.begin(), v.end());
  int z = 0;
  l = 0;
  for (int i = 0; i < (int)w.size(); i++) {
    l += (a[x + w[i].first][y + w[i].second] == mx) ? 1 : 0;
    if (a[x + w[i].first][y + w[i].second] != mx) {
      if (i > 0) {
        if (a[x + w[i - 1].first][y + w[i - 1].second] == mx) {
          z++;
        }
      } else {
        if (a[x + w[w.size() - 1].first][y + w[w.size() - 1].second] == mx) {
          z++;
        }
      }
    }
  }
  if (z == 1 && l <= 8) {
    for (int i = x; i < x + h; i++) {
      for (int j = y; j < y + h; j++) {
        if (a[i][j] == mx) {
          dfs2(i, j, mx, 20);
        }
      }
    }
    return mx;
  }
  return -1;
}
void solve(int x1, int y1, int x2, int y2, int h) {
  for (int i = x1; i < x2; i++) {
    for (int j = y1; j < y2; j++) {
      if (j > y1) {
        for (int x = i; x < i + h; x++) {
          g(x, j + h - 1);
          u(x, j - 1);
        }
      } else {
        for (int q = 0; q < (int)t.size(); q++) {
          t[q] = 0;
        }
        for (int x = i; x < i + h; x++) {
          for (int y = j; y < j + h; y++) {
            g(x, y);
          }
        }
      }
      int x = test(i, j, h);
      if (x > 0) {
        ans[x - 2]++;
        for (int q = 0; q < (int)t.size(); q++) {
          t[q] = 0;
        }
        for (int x = i; x < i + h; x++) {
          for (int y = j; y < j + h; y++) {
            g(x, y);
          }
        }
      }
    }
  }
}
int main() {
  int n, m;
  memset(a, 0, sizeof(a));
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[5 + i][5 + j]);
    }
  }
  n += 15;
  m += 15;
  k = 0;
  vector<double> d1, d2, dn;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 1) {
        dfs(i, j, k + 2);
        k++;
        d1.push_back(i);
        d2.push_back(j);
        dn.push_back(1);
      } else {
        if (a[i][j] > 1) {
          d1[a[i][j] - 2] += i;
          d2[a[i][j] - 2] += j;
          dn[a[i][j] - 2]++;
        }
      }
    }
  }
  cout << k << endl;
  t.resize(k + 5);
  int h = 7;
  for (int i = 0; i < 0 + h - 1; i++) {
    w.push_back(make_pair(i, 0));
  }
  for (int i = 0; i < 0 + h - 1; i++) {
    w.push_back(make_pair(h - 1, i));
  }
  for (int i = 0 + h - 1; i > 0; i--) {
    w.push_back(make_pair(i, 0 + h - 1));
  }
  for (int i = 0 + h - 1; i > 0; i--) {
    w.push_back(make_pair(0, i));
  }
  ans.resize(k);
  for (int i = 0; i < k; i++) {
    int dx = (int)d1[i] / dn[i];
    int dy = (int)d2[i] / dn[i];
    int w = 150;
    int x1 = max(0, dx - w), x2 = min(n - h, dx + w - h);
    int y1 = max(0, dy - w), y2 = min(m - h, dy + w - h);
    solve(x1, y1, x2, y2, h);
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < k; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
