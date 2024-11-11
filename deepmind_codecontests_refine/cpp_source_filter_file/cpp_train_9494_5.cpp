#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    map<char, int> mp;
    int n;
    cin >> n;
    int R, P, S;
    cin >> R >> P >> S;
    string s;
    cin >> s;
    for (auto i : s) mp[i]++;
    int ans = min(R, mp['S']) + min(P, mp['R']) + min(S, mp['P']);
    if (ans >= (n + 1) / 2) {
      cout << "YES\n";
      vector<char> sol(n, 'X');
      for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
          if (P) {
            sol[i] = 'P';
            P--;
          }
        } else if (s[i] == 'P') {
          if (S) {
            sol[i] = 'S';
            S--;
          }
        } else {
          if (R) {
            sol[i] = 'R';
            R--;
          }
        }
      }
      for (int i = 0; i < n; i++) {
        if (s[i] == 'X') {
          if (R) {
            sol[i] = 'R';
            R--;
          } else if (P) {
            sol[i] = 'P';
            P--;
          } else if (S) {
            sol[i] = 'S';
            S--;
          }
        }
      }
      for (auto i : sol) cout << i;
    } else {
      cout << "NO";
    }
    cout << endl;
  }
  return 0;
}
