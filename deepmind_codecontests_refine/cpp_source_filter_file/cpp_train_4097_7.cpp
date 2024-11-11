#include <bits/stdc++.h>
using namespace std;
int main() {
  queue<int> q[26];
  string s;
  int massimo = 0, inf = 0;
  cin.tie(0);
  cin.sync_with_stdio(0);
  cout.tie(0);
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    q[s[i] - 'a'].push(i);
    massimo = max(massimo, s[i] - 'a');
  }
  do {
    while (!q[massimo].empty()) {
      if (q[massimo].front() > inf) cout << (char)('a' + massimo);
      if (q[massimo].size() == 1) inf = max(inf, q[massimo].front());
      q[massimo].pop();
    }
    massimo--;
  } while (massimo >= 0);
  cout << endl;
  return 0;
}
