#include <bits/stdc++.h>
using namespace std;
char s[100000];
int vis[100000];
int n, ans = 0;
void visit(int i) {
  int cot = 0;
  for (int j = i; j < n; j++) {
    vis[j] = 1;
    cot++;
    if (s[j] == 'L') {
      ans += cot % 2;
      return;
    }
  }
}
int main() {
  memset(vis, 0, sizeof(vis));
  cin >> n;
  getchar();
  gets(s);
  int cot = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == 'R') visit(i);
  for (int i = 0; i < n; i++) ans += (vis[i] == 0);
  for (int i = 0; i < n; i++) {
    if (vis[i]) break;
    if (s[i] == 'L') {
      ans -= (i + 1);
      break;
    }
  }
  int x;
  cout << ans << endl;
  cin >> x;
}
