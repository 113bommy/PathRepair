#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = 2000000000;
const long long BIG = 1446803456761533460LL;
const int maxn = 300010;
const int SQ = 500;
int T, n, q;
vector<int> A[maxn];
int I[maxn];
vector<pair<int, int> > O[maxn];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  memset(I, -1, sizeof I);
  cin >> T;
  for (int tt = 0; tt < T; ++tt) {
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
      int k;
      cin >> k;
      A[i].resize(k);
      for (int j = 0; j < k; ++j) cin >> A[i][j], --A[i][j];
    }
    bool flag = false;
    for (int i = 0; i < q; ++i) {
      if (A[i].size() <= SQ) continue;
      for (int j = 0; j < A[i].size(); ++j) I[A[i][j]] = j;
      for (int k = 0; k < n; ++k) {
        if (i == k) continue;
        int mx = -1;
        for (int j = (A[k].size()) - 1; j >= 0; --j) {
          if (I[A[k][j]] != -1 && I[A[k][j]] < mx &&
              A[k][j + 1] != A[i][I[A[k][j]] + 1]) {
            flag = true;
            break;
          }
          mx = max(mx, (I[A[k][j]]));
        }
        if (flag) break;
      }
      for (int j = 0; j < A[i].size(); ++j) I[A[i][j]] = -1;
      if (flag) break;
    }
    if (flag) {
      cout << "Human\n";
      continue;
    }
    for (int i = 0; i < q; ++i) {
      if (A[i].size() > SQ) continue;
      for (int j = 0; j < A[i].size(); ++j) O[A[i][j]].emplace_back(i, j);
    }
    for (int i = 0; i < n; ++i) {
      for (auto [k, t] : O[i]) {
        for (int j = 0; j < t; ++j) {
          if (I[A[k][j]] != -1 && I[A[k][j]] != A[k][j + 1]) {
            flag = true;
            break;
          } else
            I[A[k][j]] = A[k][j + 1];
        }
        if (flag) break;
      }
      for (auto [k, t] : O[i]) {
        for (int j = 0; j < t; ++j) {
          I[A[k][j]] = -1;
        }
      }
      if (flag) break;
    }
    for (int i = 0; i < n; ++i) O[i].clear();
    if (flag)
      cout << "Human\n";
    else
      cout << "Robot\n";
  }
}
