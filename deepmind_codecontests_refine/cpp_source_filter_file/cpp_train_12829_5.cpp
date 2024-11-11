#include <bits/stdc++.h>
using namespace std;
const int MAXA = 100;
int T, N, a[200010];
int save[210], S[MAXA + 1][200001];
vector<int> v, memo;
void SOLVE() {
  int ANS = 0;
  for (int j = 1; j <= MAXA; ++j) {
    for (int i = 1; i <= N; ++i) {
      S[j][i] = S[j][i - 1] + (bool)(a[i] == j);
    }
    ANS = max(ANS, S[j][N]);
  }
  for (int j = 0; j < v.size(); ++j) {
    int A = v[j];
    memo.clear();
    for (int i = 1; i <= N; ++i) {
      if (a[i] == A) memo.push_back(i);
    }
    for (int x = 1; x <= memo.size() / 2; ++x) {
      int l = memo[x - 1];
      if (memo.size() - x < 0) continue;
      int r = memo[memo.size() - x];
      int y = 0;
      ++l;
      --r;
      if (l <= r) {
        for (int i = 1; i <= MAXA; ++i) {
          y = max(y, S[i][r] - S[i][l - 1]);
        }
      }
      ANS = max(ANS, x + y + x);
    }
  }
  cout << ANS;
  for (int j = 0; j <= MAXA; ++j) {
    for (int i = 0; i <= N; ++i) {
      S[j][i] = 0;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> N;
    v.clear();
    memset(save, 0, sizeof(save));
    for (int i = 1; i <= N; ++i) {
      cin >> a[i];
      if (!save[a[i]]) {
        save[a[i]] = 1;
        v.push_back(a[i]);
      }
    }
    SOLVE();
    cout << '\n';
  }
}
