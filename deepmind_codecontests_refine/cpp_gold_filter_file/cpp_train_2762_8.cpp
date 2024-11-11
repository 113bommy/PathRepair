#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int ss, res = 0;
    string s;
    cin >> s, ss = s.size() - 4;
    for (int i = 4; i < ss + 4; i++) res *= 10, res += s[i] - '0';
    cout << (ss == 1     ? (res == 9 ? 1989 : 1990 + res)
             : (ss == 2) ? (res == 99 ? 1999 : 2000 + res)
             : (ss == 3) ? (res >= 0 && res < 99 ? 3000 + res : 2000 + res)
             : ((ss == 4 && res < 3099) || (ss == 5 && res < 13099) ||
                (ss == 6 && res < 113099) || (ss == 7 && res < 1113099) ||
                (ss == 8 && res < 11113099) || (ss == 9 && res < 111113099))
                 ? (int)pow(10, ss) + res
                 : res)
         << '\n';
  }
  return 0;
}
