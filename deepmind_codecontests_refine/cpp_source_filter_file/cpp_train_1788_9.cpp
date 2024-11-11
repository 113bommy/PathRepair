#include <bits/stdc++.h>
using namespace std;
int n, m;
int board[2000][2000];
int cnt[2000000];
int cntsum[2000000];
int sum[2000][2000];
int invsum[2000][2000];
void flipdown() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      board[n + i][j] = !board[i][j];
    }
  }
  n <<= 1;
}
void flipright() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      board[i][m + j] = !board[i][j];
    }
  }
  m <<= 1;
}
void expand() {
  int s = 2;
  cnt[1] = 1;
  while (s < 1000000) {
    for (int i = 0; i < s; i++) {
      cnt[s + i] = !cnt[i];
    }
    s <<= 1;
  }
  for (int i = 1; i < 2000000; i++) {
    cntsum[i] += cntsum[i - 1];
  }
}
bool isinv(int x, int y) {
  if (y) {
    bool ret = isinv(x, 0);
    return cnt[y] ? !ret : ret;
  }
  return cnt[x];
}
long long full(int x, int y) {
  if (x == 0 || y == 0) return 0;
  long long ret = (sum[n][m] + invsum[n][m]) * (1ll * x * y / 2);
  if (x & 1 && y & 1) {
    ret += isinv(x - 1, y - 1) ? invsum[n][m] : sum[n][m];
  }
  return ret;
}
int corner(bool inv, int x, int y) { return inv ? invsum[x][y] : sum[x][y]; }
long long vertical(int hcnt, int wcnt, int y) {
  if (hcnt == 0) return 0;
  int inv = cntsum[hcnt - 1];
  if (cnt[wcnt]) {
    inv = hcnt - inv;
  }
  return 1ll * (hcnt - inv) * sum[n][y] + 1ll * inv * invsum[n][y];
}
long long horizontal(int hcnt, int wcnt, int x) {
  if (wcnt == 0) return 0;
  int inv = cntsum[wcnt - 1];
  if (cnt[hcnt]) {
    inv = wcnt - inv;
  }
  return 1ll * (wcnt - inv) * sum[x][m] + 1ll * inv * invsum[x][m];
}
long long get(int x, int y) {
  int hcnt = x / n;
  int wcnt = y / m;
  long long ret = 0;
  ret += full(hcnt, wcnt);
  ret += vertical(hcnt, wcnt, y % m);
  ret += horizontal(hcnt, wcnt, x % n);
  ret += corner(isinv(hcnt, wcnt), x % n, y % m);
  return ret;
}
void debug() {
  cout << "C: " << endl;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }
  cout << "I: " << endl;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      cout << !board[i][j];
    }
    cout << endl;
  }
  cout << "Sum C: " << endl;
  for (int i = 0; i <= 20; i++) {
    for (int j = 0; j <= 20; j++) {
      cout << sum[i][j] << '\t';
    }
    cout << endl;
  }
  cout << "Sum I: " << endl;
  for (int i = 0; i <= 20; i++) {
    for (int j = 0; j <= 20; j++) {
      cout << invsum[i][j] << '\t';
    }
    cout << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  expand();
  int q;
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      board[i][j] = s[j] - '0';
    }
  }
  while (n < 1000) {
    flipdown();
  }
  while (m < 1000) {
    flipright();
  }
  assert(n >= 1000 && m >= 1000);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      sum[i + 1][j + 1] = board[i][j];
      invsum[i + 1][j + 1] = !board[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      sum[i][j] += sum[i - 1][j];
      invsum[i][j] += invsum[i - 1][j];
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      sum[i][j] += sum[i][j - 1];
      invsum[i][j] += invsum[i][j - 1];
    }
  }
  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long ans =
        get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
    cout << ans << '\n';
  }
}
