#include <bits/stdc++.h>
using namespace std;
void err() {
  cout << "shit" << endl;
  exit(1);
}
const int maxn = 1e6 + 10;
int nxt[maxn * 2];
void go_next(string s) {
  int len = s.length();
  nxt[0] = -1;
  int j = 0, k = -1;
  while (j < len) {
    if (k == -1 || s[j] == s[k])
      nxt[++j] = ++k;
    else
      k = nxt[k];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  n--;
  string s, t;
  cin >> s >> t;
  reverse(s.begin(), s.end());
  int len = s.length();
  for (int i = 0; i < len; i++) {
    if (s[i] == 'N')
      s[i] = 'S';
    else if (s[i] == 'S')
      s[i] = 'N';
    else if (s[i] == 'W')
      s[i] = 'E';
    else
      s[i] = 'W';
  }
  s += t;
  go_next(s);
  if (nxt[s.length()])
    cout << "NO";
  else
    cout << "YES";
  cout << "\n";
  return 0;
}
