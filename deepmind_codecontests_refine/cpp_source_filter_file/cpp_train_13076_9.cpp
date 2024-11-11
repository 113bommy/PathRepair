#include <bits/stdc++.h>
using namespace std;
int n, sol, q;
string s[1001], t;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    s[i] = t;
  }
  for (int i = 0; i < 7; i++) {
    q = 0;
    for (int j = 0; j < n; j++)
      if (s[j][i] == '1') q++;
    sol = max(sol, q);
  }
  printf("%d", max(sol, 1));
  return 0;
}
