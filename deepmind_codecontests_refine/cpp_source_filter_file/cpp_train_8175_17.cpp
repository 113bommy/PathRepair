#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
char a[1100];
pair<char, char> b[40] = {
    {'A', 'A'}, {'T', 'T'}, {'Y', 'Y'}, {'U', 'U'}, {'H', 'H'}, {'I', 'I'},
    {'M', 'M'}, {'O', 'O'}, {'T', 'T'}, {'V', 'V'}, {'W', 'W'}, {'X', 'X'},
    {'b', 'd'}, {'p', 'q'}, {'o', 'o'}, {'v', 'v'}, {'w', 'w'}, {'x', 'x'}};
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> (a + 1);
  int len = strlen(a + 1);
  for (int i = 1; i <= (len + 1) / 2; i++) {
    int las = len - i + 1;
    bool f = 0;
    for (int j = 0; j < 18; j++) {
      if (a[i] == b[j].first) {
        f = 1;
        if (a[las] == b[j].second) break;
        cout << "NIE" << '\n';
        return 0;
      }
      if (a[i] == b[j].second) {
        f = 1;
        if (a[las] == b[j].second) break;
        cout << "NIE" << '\n';
        return 0;
      }
    }
    if (!f) {
      cout << "NIE" << '\n';
      return 0;
    }
  }
  cout << "TAK" << '\n';
  return 0;
}
