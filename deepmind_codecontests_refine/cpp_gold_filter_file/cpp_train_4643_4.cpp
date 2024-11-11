#include <bits/stdc++.h>
using namespace std;
string S, T, U;
int N;
char is[101010];
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> S;
  N = S.size();
  char c = 'z' + 1;
  for (i = N - 1; i >= 0; i--) {
    is[i] = c;
    c = min(c, S[i]);
  }
  for (i = 0; i < (N); i++) {
    while (T.size() && T.back() <= min(is[i], S[i])) {
      U.push_back(T.back());
      T.pop_back();
    }
    if (is[i] < S[i]) {
      T.push_back(S[i]);
    } else {
      while (T.size() && T.back() <= S[i]) {
        U.push_back(T.back());
        T.pop_back();
      }
      U.push_back(S[i]);
    }
  }
  while (T.size()) {
    U.push_back(T.back());
    T.pop_back();
  }
  cout << U << endl;
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  solve();
  return 0;
}
