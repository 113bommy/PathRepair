#include <bits/stdc++.h>
using namespace std;
int f(char c) {
  if (c == 'q') return 9;
  if (c == 'r') return 5;
  if (c == 'b') return 3;
  if (c == 'n') return 3;
  if (c == 'p') return 1;
  return 0;
}
int MAIN() {
  int x = 0;
  for (int i = 0; i < 8; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 8; j++) {
      char c = s[j];
      if ('A' <= c && c <= 'Z')
        x -= f(c - 'A' + 'a');
      else
        x += f(c);
    }
  }
  if (x < 0) cout << "White" << endl;
  if (x == 0) cout << "Draw" << endl;
  if (x > 0) cout << "Black" << endl;
  return 0;
}
int main() {
  int start = clock();
  ios ::sync_with_stdio(false);
  cout << fixed << setprecision(16);
  int ret = MAIN();
  return ret;
}
