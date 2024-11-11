#include <bits/stdc++.h>
using namespace std;
bool Check(int N, int pos) { return (bool)(N & (1 << pos)); }
int Set(int N, int pos) { return (N | (1 << pos)); }
long long BigMod(long long B, long long P, long long M) {
  long long R = 1;
  while (P > 0) {
    if (P % 2 == 1) {
      R = (R * B) % M;
    }
    P /= 2;
    B = (B * B) % M;
  }
  return R;
}
const long long mod = 1000000007;
string str[105];
int ara[105];
int vis[205];
int got[204];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> str[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> ara[i];
    got[ara[i] - 1] = 1;
  }
  for (int i = 1; i < m; i++) {
    if (str[ara[i - 1] - 1].length() != str[ara[i] - 1].length()) {
      cout << "No\n";
      return 0;
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < str[ara[i] - 1].size(); j++) {
      int d = str[ara[i] - 1][j];
      if (vis[j] == -1) continue;
      if (vis[j] == 0) {
        vis[j] = d;
      } else if (vis[j] != d) {
        vis[j] = -1;
      }
    }
  }
  string s;
  for (int i = 0; i < str[ara[0] - 1].size(); i++) {
    if (vis[i] == -1)
      s += "?";
    else
      s += (char)vis[i];
  }
  for (int i = 0; i < n; i++) {
    if (got[i] == 0) {
      int match = 1;
      if (str[i].size() != s.size()) continue;
      for (int j = 0; j < s.size(); j++) {
        if (s[j] == '?') continue;
        if (s[j] != str[i][j]) {
          match = 0;
          break;
        }
      }
      if (match) {
        cout << "No\n";
        return 0;
      }
    } else {
      if (s.size() != str[i].size()) {
        cout << "No\n";
        return 0;
      }
    }
  }
  cout << "Yes\n";
  cout << s << "\n";
}
