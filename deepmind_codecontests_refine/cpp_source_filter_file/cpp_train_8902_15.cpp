#include <bits/stdc++.h>
using namespace std;
int n;
int d[100005];
int vis[100005];
char s[100005];
int main() {
  cin >> n;
  cin >> s + 1;
  for (int i = 1; i <= n; i++) cin >> d[i];
  int p = 1;
  while (p >= 1 && p <= n) {
    if (vis[p]) {
      cout << "FINITE" << endl;
      return 0;
    }
    vis[p] = 1;
    if (s[p] == '<') {
      p -= d[p];
    } else {
      p += d[p];
    }
  }
  cout << "INFINITE" << endl;
  return 0;
}
