#include <bits/stdc++.h>
using namespace std;
int vis[] = {0, 1, 6, 1, 2, 2, 3, 1, 4, 0, 1};
int main() {
  string s;
  cin >> s;
  int a = s[0] - '0', b = s[1] - '0';
  cout << (vis[a] + 1) * (vis[b] + 1);
}
