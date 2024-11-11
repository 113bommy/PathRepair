#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, res[6] = {"Power", "Time", "Space", "soul", "Reality", "Mind"},
            color[6] = {"purple", "green", "blue", "orange", "red", "yellow"};
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    res[find(color, color + 6, s) - color] = "-1";
  }
  cout << 6 - n << endl;
  for (int i = 0; i < 6; i++)
    if (res[i] != "-1") cout << res[i] << endl;
  return 0;
}
