#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  string s;
  int n = 8;
  int white = 0, black = 0;
  while (n--) {
    cin >> s;
    white += count(s.begin(), s.end(), 'Q') * 9;
    white += count(s.begin(), s.end(), 'R') * 5;
    white += count(s.begin(), s.end(), 'B') * 3;
    white += count(s.begin(), s.end(), 'N') * 3;
    white += count(s.begin(), s.end(), 'P') * 1;
    black += count(s.begin(), s.end(), 'q') * 9;
    black += count(s.begin(), s.end(), 'r') * 5;
    black += count(s.begin(), s.end(), 'b') * 3;
    black += count(s.begin(), s.end(), 'n') * 3;
    black += count(s.begin(), s.end(), 'p') * 1;
  }
  if (white > black) {
    cout << "White\n";
  } else if (white == black) {
    cout << "Draw\n";
  } else {
    cout << "Black\n";
  }
}
