#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v[100001];
int visited[100001];
int d[100001];
bool allCharactersSame(string s) {
  int n = s.length();
  for (int i = 1; i < n; i++)
    if (s[i] != s[0]) return false;
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c = 0;
    int d = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '<') c = 1;
      if (s[i] == '>') d = 1;
    }
    if (c == 1 && d == 1) {
      int ans = 0;
      s += s[0];
      for (int i = 0; i < n; i++) {
        if (s[i] == '-' || s[i + 1] == '-') ans++;
      }
      cout << ans << "\n";
    } else {
      cout << n << "\n";
    }
  }
}
