#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int f[maxn];
int g[maxn];
string s;
string b[15];
int n;
bool legal(string s) {
  for (int i = 1; i <= n; i++) {
    if (b[i] == s) return false;
  }
  return true;
}
void dp() {
  int i;
  bool flag = false;
  memset(f, 0, sizeof(f));
  for (i = 1; i <= n; i++) {
    if (b[i].length() == 1) {
      if (b[i][0] == s[0]) {
        flag = true;
        break;
      }
    }
  }
  if (flag) {
    f[0] = 0;
    g[0] = 0;
  } else {
    f[0] = 1;
    g[0] = 0;
  }
  int l = s.length();
  int ans = 0, Pos = 0;
  for (i = 1; i < l; i++) {
    string ss = "";
    ss = ss + s[i];
    if (legal(ss)) {
      f[i] = 1;
      g[i] = i;
    } else
      continue;
    int pos = i - f[i - 1];
    ss = s.substr(pos, i - pos + 1);
    f[i] = i - pos + 1;
    g[i] = pos;
    ss = "";
    int p = i, k = 0;
    while (p >= pos && k < 10) {
      k++;
      ss = s[p] + ss;
      if (!legal(ss)) {
        f[i] = i - p;
        g[i] = p + 1;
        break;
      }
      p--;
    }
    if (f[i] > ans) {
      ans = f[i];
      Pos = g[i];
    }
  }
  cout << ans << " " << Pos << endl;
}
int main() {
  int i;
  while (cin >> s) {
    cin >> n;
    for (i = 1; i <= n; i++) {
      cin >> b[i];
    }
    dp();
  }
  return 0;
}
