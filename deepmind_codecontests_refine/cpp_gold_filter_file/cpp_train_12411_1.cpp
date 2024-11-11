#include <bits/stdc++.h>
using namespace std;
char s[65], t[65], c[] = "OHC";
int n;
void ask() {
  cout << "? " << t + 1 << endl;
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int pos;
    cin >> pos;
    --pos;
    for (int j = 1; t[j] > 0; j++) s[pos + j] = t[j];
  }
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    memset(s, 0, sizeof(s));
    memset(t, 0, sizeof(t));
    t[1] = 'C';
    t[2] = 'C';
    ask();
    t[1] = 'C';
    t[2] = 'H';
    ask();
    t[1] = 'C';
    t[2] = 'O';
    ask();
    t[1] = 'H';
    t[2] = 'O';
    ask();
    if (n == 4 && !s[1] && s[2] && s[3] && !s[4]) {
      for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
          memcpy(t + 1, s + 1, sizeof(char) * n), t[1] = c[i], t[4] = c[j],
                                                  ask();
    } else {
      t[1] = 'O';
      t[2] = 'O';
      ask();
      for (int i = 2; i < n; i++)
        if (!s[i]) s[i] = 'H';
      if (n == 4 && !s[1] && s[2] == 'H' && s[3] == 'H' && !s[4]) {
        t[1] = 'H';
        t[2] = 'H';
        t[3] = 'H';
        ask();
        if (!s[1]) s[1] = 'O';
        if (!s[4]) s[4] = 'C';
      } else {
        for (int i = 0; i < 3; i++)
          for (int j = 0; j < 3; j++) {
            if ((i == 2 && !s[1]) || (!j && !s[n]) || (s[1] && s[1] != c[i]) ||
                (s[n] && s[n] != c[j]) || (!s[1] && !s[n] && i == 1 && j == 2))
              continue;
            memcpy(t + 1, s + 1, sizeof(char) * n);
            t[1] = c[i];
            t[n] = c[j];
            ask();
          }
        if (!s[1] && !s[n]) s[1] = 'H', s[n] = 'C';
      }
    }
    cout << "! " << (s + 1) << endl;
    int stat;
    cin >> stat;
    if (!stat) break;
  }
  return 0;
}
