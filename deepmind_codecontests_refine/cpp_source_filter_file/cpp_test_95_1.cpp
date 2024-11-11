#include <bits/stdc++.h>
using namespace std;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
const int MXN = 1e5 + 5, INF = 1e9 + 5;
void solve() {
  int N, M;
  cin >> N >> M;
  int A[N][M], sm[N][M], lg[N][M];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
      sm[i][j] = lg[i][j] = A[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = M - 2; j >= 0; j--) {
      lg[i][j] = max(lg[i][j], lg[i][j + 1]);
      sm[i][j] = min(sm[i][j], sm[i][j + 1]);
    }
  }
  vector<int> smallest(N, INF), greatest(N, -INF);
  vector<int> rows(N);
  for (int i = 0; i < N; i++) rows[i] = i;
  for (int j = 0; j < M - 1; j++) {
    for (int i = 0; i < N; i++) {
      smallest[i] = min(smallest[i], A[i][j]);
      greatest[i] = max(greatest[i], A[i][j]);
    }
    sort((rows).begin(), (rows).end(), [&](const int &x, const int &y) {
      return make_pair(greatest[x], smallest[x]) <
             make_pair(greatest[y], smallest[y]);
    });
    vector<int> suf_mn(N, INF), pref_mn(N, INF), suf_mx(N, -INF);
    suf_mn[N - 1] = smallest[rows[N - 1]];
    pref_mn[0] = sm[rows[0]][j + 1];
    suf_mx[N - 1] = lg[rows[N - 1]][j + 1];
    for (int i = N - 2, j = 1; i >= 0; i--, j++) {
      suf_mn[i] = min(suf_mn[i + 1], smallest[rows[i]]);
      pref_mn[j] = min(pref_mn[j - 1], sm[rows[j]][j + 1]);
      suf_mx[i] = max(suf_mx[i + 1], lg[rows[i]][j + 1]);
    }
    for (int i = 0; i < N - 1; i++) {
      if (greatest[rows[i]] < suf_mn[i + 1] && pref_mn[i] > suf_mx[i + 1]) {
        cout << "YES\n";
        vector<char> ans(N, 'R');
        for (int k = 0; k <= i; k++) {
          ans[rows[k]] = 'B';
        }
        for (const auto &x : ans) cout << x;
        cout << " " << j + 1 << "\n";
        return;
      }
    }
  }
  cout << "NO\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int TC = 1;
  cin >> TC;
  while (TC--) solve();
}
