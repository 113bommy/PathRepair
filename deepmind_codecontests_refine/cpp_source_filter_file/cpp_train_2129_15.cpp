#include <bits/stdc++.h>
using namespace std;
int n, rez = (1 << 30);
vector<string> cards;
int getCode(char c) {
  if (c == 'R') return 0;
  if (c == 'G') return 1;
  if (c == 'B') return 2;
  if (c == 'Y') return 3;
  return 4;
}
int nrb(int s) {
  int r = 0;
  for (; s; s &= (s - 1), ++r)
    ;
  return r;
}
int knows(int s, int p) { return (s & (1 << p)); }
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    cards.push_back(s);
  }
  for (int s = 0; s < (1 << 10); ++s) {
    int ok = 1;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        if (cards[i] == cards[j]) continue;
        if (cards[i][0] != cards[j][0] && (knows(s, getCode(cards[i][0]) + 5) ||
                                           knows(s, getCode(cards[j][0]) + 5)))
          continue;
        if (cards[i][1] != cards[j][1] &&
            (knows(s, cards[i][1] - '1') || knows(s, cards[i][1] - '1')))
          continue;
        ok = 0;
      }
    if (ok) rez = min(rez, nrb(s));
  }
  cout << rez;
}
