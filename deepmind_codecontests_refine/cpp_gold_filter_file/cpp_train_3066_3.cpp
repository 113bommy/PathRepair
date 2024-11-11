#include <bits/stdc++.h>
using namespace std;
string s, s1, s2;
map<string, int> m;
int main() {
  int n, i, j;
  while (scanf("%d", &n) == 1) {
    j = 0;
    for (i = 1; i <= n; i++) {
      cin >> s1;
      cin >> s2;
      s = s1 + ' ' + s2;
      if (m[s] == 0) {
        j++;
      }
      m[s]++;
    }
    printf("%d\n", j);
  }
  return 0;
}
