#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, int> m{{'q', 9},  {'r', 5},  {'b', 3},  {'k', 3},  {'p', 1},
                   {'Q', -9}, {'R', -5}, {'B', -3}, {'K', -3}, {'P', -1}};
  int x = 0;
  for (int i = 0; i < (int)(8); ++i) {
    string s;
    cin >> s;
    for (char c : s) x += m[c];
  }
  if (x == 0)
    cout << "Draw" << endl;
  else if (x < 0)
    cout << "White" << endl;
  else
    cout << "Black" << endl;
}
