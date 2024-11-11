#include <bits/stdc++.h>
using namespace std;
int n, m, i;
string s;
int main() {
  scanf("%d%d", &n, &m);
  cin >> s;
  int x = s.find('G');
  int y = s.find('T');
  if (x > y) swap(x, y);
  for (i = x; i < y; i += m) {
    if (s[i] == '#') break;
  }
  printf("%s\n", (s[i] == 'T') ? "YES" : "NO");
}
