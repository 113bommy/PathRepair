#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vec<T>>;
template <class T>
bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
void solve() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  vec<pair<int, int>> ans;
  for (int i = 0; i < (2 * K - 2); i++) {
    int r = 0;
    for (int j = i; j < N; j++) {
      if (i % 2 == 0) {
        if (S[j] == '(') {
          r = j;
          break;
        }
      } else {
        if (S[j] == ')') {
          r = j;
          break;
        }
      }
    }
    ans.emplace_back(i, r);
    reverse(S.begin() + i, S.begin() + r + 1);
  }
  for (int i = 2 * K - 2; i < N; i++) {
    for (int j = i; j < N; j++)
      if (S[j] == '(') {
        ans.emplace_back(i, j);
        reverse(S.begin() + i, S.begin() + j + 1);
        break;
      }
  }
  cout << ans.size() << "\n";
  for (auto& [l, r] : ans) cout << l + 1 << " " << r + 1 << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
