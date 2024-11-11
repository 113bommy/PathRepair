#include <bits/stdc++.h>
using namespace std;
int n, i, lu, j, v[110], nr;
char st[110];
int main() {
  ifstream f("");
  cin >> n;
  for (i = 1; i <= n; ++i) cin >> v[i];
  gets(st);
  for (i = 1; i <= n; ++i) {
    gets(st);
    nr = 0;
    lu = strlen(st);
    for (j = 0; j < lu; ++j)
      if (st[j] == 'a' || st[j] == 'e' || st[j] == 'i' || st[j] == 'o' ||
          st[j] == 'u' || st[j] == 'y')
        ++nr;
    if (v[i] != nr) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
