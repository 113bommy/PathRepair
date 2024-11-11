#include <bits/stdc++.h>
using namespace std;
string s;
int scoreA = 0, scoreB = 0, len = 0;
void solve() {
  for (int i = 0; i < s.length(); i++)
    if (s[i] == 'p')
      scoreA++;
    else if (s[i] == 'b' || s[i] == 'k')
      scoreA += 3;
    else if (s[i] == 'r')
      scoreA += 5;
    else if (s[i] == 'q')
      scoreA += 9;
    else if (s[i] == 'P')
      scoreB++;
    else if (s[i] == 'B' || s[i] == 'K')
      scoreB += 3;
    else if (s[i] == 'R')
      scoreB += 5;
    else if (s[i] == 'Q')
      scoreB += 9;
}
int main() {
  while (cin >> s) {
    len++;
    solve();
    if (len == 8) {
      if (scoreA == scoreB)
        cout << "Draw";
      else if (scoreA < scoreB)
        cout << "White";
      else
        cout << "Black";
      cout << endl;
      scoreA = scoreB = len = 0;
    }
  }
}
