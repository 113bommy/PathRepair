#include <bits/stdc++.h>
using namespace std;
string st;
int cnt[30], dif;
int used[30][5001][30];
int tmp[30][5001];
int best[30];
set<int> s[30];
signed main() {
  cin >> st;
  st = st + st;
  for (int i = 0; i < st.size() / 2; i++) {
    for (int l = 1; l < st.size(); l++) {
      used[st[i] - 'a'][l][st[i + l] - 'a']++;
    }
  }
  for (int i = 0; i < st.size() / 2; i++) {
    for (int l = 1; l < st.size() / 2; l++) {
      int j = st[i + l] - 'a';
      if (used[st[i] - 'a'][l][j] == 1) {
        tmp[st[i] - 'a'][l]++;
        s[st[i] - 'a'].insert(l);
      }
    }
  }
  int ans = 0;
  for (int i = 'a' - 'a'; i <= 'z' - 'a'; i++) {
    for (auto j : s[i]) {
      best[i] = max(tmp[i][j], best[i]);
    }
    ans += best[i];
  }
  cout << (double)(ans) / (st.size() / 2) << endl;
}
