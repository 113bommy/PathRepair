#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline bool umin(T1& x, const T2& y) {
  return x > y ? x = y, true : false;
}
template <typename T1, typename T2>
inline bool umax(T1& x, const T2& y) {
  return x < y ? x = y, true : false;
}
const int N = (int)1e3 + 7;
const int mod = (int)1e9 + 7;
const int INF = (int)1e9 + 17;
const long long LLINF = (long long)1e18 + 17;
const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int n, m;
char f[N][N];
char t[N][N];
bool isCorrect() {
  for (int x = (0); x < (n); ++x)
    for (int y = (0); y < (m); ++y) {
      for (int i = (0); i < (8); ++i) {
        int px = x + dx[i];
        int py = y + dy[i];
        if (px < 0 || px >= n) continue;
        if (py < 0 || py >= m) continue;
        if (f[px][py] == f[x][y]) return false;
      }
    }
  return true;
}
void paint(const vector<int>& perm) {
  memcpy(t, f, sizeof(f));
  for (int i = (0); i < (n); ++i) {
    char x1 = '0' + perm[2 * (i % 2)];
    char x2 = '0' + perm[2 * (i % 2) + 1];
    for (int j = (0); j < (m); ++j) {
      if (f[i][j] != '0') {
        if (j % 2 == 0 && x1 != f[i][j])
          swap(x1, x2);
        else if (j % 2 == 1 && x2 != f[i][j])
          swap(x1, x2);
        break;
      }
    }
    for (int j = (0); j < (m); ++j) {
      if (f[i][j] == '0') f[i][j] = (j % 2 == 0 ? x1 : x2);
    }
  }
}
void paint2(const vector<int>& perm) {
  memcpy(t, f, sizeof(f));
  for (int i = (0); i < (m); ++i) {
    char x1 = '0' + perm[2 * (i % 2)];
    char x2 = '0' + perm[2 * (i % 2) + 1];
    for (int j = (0); j < (n); ++j) {
      if (f[j][i] != '0') {
        if (j % 2 == 0 && x1 != f[i][j])
          swap(x1, x2);
        else if (j % 2 == 1 && x2 != f[i][j])
          swap(x1, x2);
        break;
      }
    }
    for (int j = (0); j < (n); ++j) {
      if (f[j][i] == '0') f[j][i] = (j % 2 == 0 ? x1 : x2);
    }
  }
}
void restore() { memcpy(f, t, sizeof(t)); }
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n >> m;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) cin >> f[i][j];
  vector<int> perm = {1, 2, 3, 4};
  bool res = false;
  do {
    paint(perm);
    res = isCorrect();
    if (res) break;
    restore();
  } while (next_permutation((perm).begin(), (perm).end()));
  perm = {1, 2, 3, 4};
  do {
    if (res) break;
    paint2(perm);
    res = isCorrect();
    if (res) break;
    restore();
  } while (next_permutation((perm).begin(), (perm).end()));
  if (!res) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (m); ++j) cout << f[i][j];
    cout << '\n';
  }
  return 0;
}
