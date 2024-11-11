#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10, MN = 1e3 + 5, MK = 3e5 + 5;
long long D[MK];
string s[MN];
int n, m, k;
struct trip {
  int a, b, c, d, ch;
} rec[MK];
struct mat {
  long long A[1005][1005];
  mat() { memset(A, 0, sizeof A); }
  void clear() { memset(A, 0, sizeof A); }
  void P() {
    for (int i = 0; i < MN; ++i)
      for (int j = 0; j < MN; ++j) {
        if (i) A[i][j] += A[i - 1][j];
        if (j) A[i][j] += A[i][j - 1];
        if (i && j) A[i][j] -= A[i - 1][j - 1];
      }
  }
  void Add(const trip &T) {
    int a = T.a, b = T.b, c = T.c, d = T.d;
    ++A[a][b], --A[a][d + 1], --A[c + 1][b], ++A[c + 1][d + 1];
  }
  long long get(const trip &T) {
    int a = T.a, b = T.b, c = T.c, d = T.d;
    long long ret = A[c][d];
    if (b) ret -= A[c][b - 1];
    if (a) ret -= A[a - 1][d];
    if (a && b) ret += A[a - 1][b - 1];
    return ret;
  }
  void print() {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) cout << A[i][j] << ' ';
      cout << endl;
    }
  }
} Cnt[26], my;
void solve() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) Cnt[s[i][j] - 'a'].A[i][j]++;
  for (int i = 0; i < 26; ++i) Cnt[i].P();
  long long sm = 0;
  for (int i = 0; i < k; ++i) {
    for (int c = 0; c < 26; ++c)
      D[i] += 1ll * abs(rec[i].ch - c) * Cnt[c].get(rec[i]);
    sm += D[i];
  }
  for (int i = 0; i < k; ++i) D[i] = D[i] * k + sm;
  for (int i = 0; i < 26; ++i) Cnt[i].clear();
  for (int i = 0; i < k; ++i) my.Add(rec[i]);
  my.P();
  for (int r = 0; r < n; ++r)
    for (int c = 0; c < m; ++c) Cnt[s[r][c] - 'a'].A[r][c] = my.A[r][c];
  for (int i = 0; i < 26; ++i) Cnt[i].P();
  for (int i = 0; i < k; ++i)
    for (int c = 0; c < 26; ++c)
      D[i] -= 1ll * abs(rec[i].ch - c) * Cnt[c].get(rec[i]);
  my.clear();
  for (int i = 0; i < 26; ++i) Cnt[i].clear();
  for (int i = 0; i < k; ++i) Cnt[rec[i].ch].Add(rec[i]);
  for (int i = 0; i < 26; ++i) {
    Cnt[i].P();
    for (int r = 0; r < n; ++r)
      for (int c = 0; c < m; ++c)
        my.A[r][c] += 1ll * abs(s[r][c] - 'a' - i) * Cnt[i].A[r][c];
  }
  my.P();
  for (int i = 0; i < k; ++i) D[i] -= my.get(rec[i]);
  for (int i = 0; i < 26; ++i) Cnt[i].P();
  for (int i = 0; i < k; ++i)
    for (int c = 0; c < 26; ++c)
      D[i] += 1ll * abs(rec[i].ch - c) * Cnt[c].get(rec[i]);
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int i = 0; i < k; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a, --b, --c, --d;
    char ch;
    cin >> ch;
    rec[i] = {a, b, c, d, ch - 'a'};
  }
  solve();
  cout << *min_element(D, D + k) << '\n';
  return 0;
}
