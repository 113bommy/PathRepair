#include <bits/stdc++.h>
using namespace std;
void display(string s, int rock, int paper, int scissors) {
  int len = s.size();
  char c[len + 1];
  memset(c, 0, sizeof(char) * len);
  for (int i = 0; i < len; ++i) {
    if (s[i] == 'R' && paper > 0)
      --paper, c[i] = 'P';
    else if (s[i] == 'P' && scissors > 0)
      --scissors, c[i] = 'S';
    else if (s[i] == 'S' && rock > 0)
      --rock, c[i] = 'R';
  }
  for (int i = 0; i < len; ++i) {
    if (c[i] == 0) {
      if (paper > 0)
        c[i] = 'P', --paper;
      else if (rock > 0)
        c[i] = 'R', --rock;
      else if (scissors > 0)
        c[i] = 'S', --scissors;
    }
  }
  cout << c << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n, rock, paper, scissors;
    cin >> n >> rock >> paper >> scissors;
    string s;
    cin >> s;
    int r = 0, p = 0, ss = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'R')
        r++;
      else if (s[i] == 'P')
        p++;
      else
        ss++;
    }
    int ans = std::min(r, paper) + std::min(p, scissors) + std::min(ss, rock);
    if (ans >= (n + 1) / 2)
      cout << "YES\n", display(s, rock, paper, scissors);
    else
      cout << "NO\n";
  }
}
