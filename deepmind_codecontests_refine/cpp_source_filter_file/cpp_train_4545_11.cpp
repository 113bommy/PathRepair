#include <bits/stdc++.h>
using namespace std;
int ok[5002][5002];
int main() {
  string s;
  cin >> s;
  int X = 0;
  for (X = 1; (2 * X + 1) < s.size(); X = (2 * X + 1))
    ;
  struct state {
    int id, deleted, mi;
  };
  int N = s.size();
  vector<vector<state>> states(N - X);
  for (int i = 0; i <= s.size(); ++i) {
    for (int j = 0; j <= X && j <= i; ++j) {
      if (i - j >= N - X) continue;
      states[i - j].push_back((state){i, j, i == j});
      if (i == j) ok[i][j] = 1;
    }
  }
  string ans = "";
  for (int i = 0; i < states.size(); ++i) {
    if (i)
      for (state &st : states[i]) {
        for (int j = 0; j < 20; j++) {
          if (st.deleted & (1 << j)) {
            if (ok[st.id - (1 << j)][st.deleted ^ (1 << j)]) {
              ok[st.id][st.deleted] = 1;
              st.mi = 1;
              break;
            }
          }
        }
        if (ok[st.id - 1][st.deleted]) {
          ok[st.id][st.deleted] = 1;
          st.mi = 1;
        }
      }
    char mic = 'z' + 1;
    for (state &st : states[i]) {
      if (ok[st.id][st.deleted]) {
        mic = min(mic, s[st.id]);
      }
    }
    for (state &st : states[i]) {
      if (ok[st.id][st.deleted] && mic != s[st.id]) {
        ok[st.id][st.deleted] = 0;
        st.mi = 0;
      }
    }
    ans += mic;
  }
  cout << ans << endl;
}
