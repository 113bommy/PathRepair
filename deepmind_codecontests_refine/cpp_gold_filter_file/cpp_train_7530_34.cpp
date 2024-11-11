#include <bits/stdc++.h>
using namespace std;
const long long INFI = (1 << 28);
const long long mod = 1000000007;
vector<int> adj[30];
int main() {
  string st;
  cin >> st;
  for (int i = 0; i < st.size(); i++) {
    adj[st[i] - 97].push_back(i);
  }
  string ans;
  int p, last = -1;
  for (int i = 25; i >= 0; i--) {
    if (adj[i].size() > 0) {
      p = i;
      for (int j = 0; j < adj[i].size(); j++) {
        last = adj[i][j];
        ans.push_back((char)(i + 97));
      }
      break;
    }
  }
  for (int i = p - 1; i >= 0; i--) {
    if (adj[i].size() > 0) {
      int ini =
          lower_bound((adj[i]).begin(), (adj[i]).end(), last) - adj[i].begin();
      if (ini == adj[i].size()) continue;
      for (int q = ini; q < adj[i].size(); q++) {
        last = adj[i][q];
        ans.push_back(i + 97);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
