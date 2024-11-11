#include <bits/stdc++.h>
using namespace std;
int M, K, N, S;
int A[505050];
map<int, int> need, need2;
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  scanf("%d%d%d%d", &M, &K, &N, &S);
  for (i = 0; i < (M); i++) scanf("%d", &A[i]);
  for (i = 0; i < (S); i++) {
    scanf("%d", &x);
    need[x]++;
  }
  need2 = need;
  int over = need.size();
  int L, R = 0;
  for (L = 0; L < (M); L++) {
    while (R < M && (over > 0 || R - L < K)) {
      need[A[R]]--;
      if (need[A[R]] == 0) over--;
      R++;
    }
    if (over == 0 && L / K + (M - R) / K >= N - 1) {
      vector<int> ret;
      int add = min(N - 1, L / K);
      N -= add;
      for (i = 0; i < (L - add * K); i++) ret.push_back(i);
      add = min(N - 1, (M - R) / K);
      N -= add;
      for (i = 0; i < (M - R - add * K); i++) ret.push_back(M - 1 - i);
      vector<int> C;
      for (i = L; i < R; i++) {
        if (need2[A[i]]) {
          need2[A[i]]--;
        } else {
          C.push_back(i);
        }
      }
      C.resize(R - L - K);
      for (auto& c : C) ret.push_back(c);
      sort((ret.begin()), (ret.end()));
      cout << ret.size() << endl;
      for (auto& r : ret) cout << (r + 1) << " ";
      return;
    }
    if (need[A[L]] == 0) over++;
    need[A[L]]++;
  }
  cout << -1 << endl;
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  cout.tie(0);
  solve();
  return 0;
}
