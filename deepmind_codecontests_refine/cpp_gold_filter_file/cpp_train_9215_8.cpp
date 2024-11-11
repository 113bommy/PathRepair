#include <bits/stdc++.h>
using namespace std;
int x[203], y[203];
char s[203];
int main() {
  ifstream in("a.in");
  ofstream out("a.out");
  int n;
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    switch (s[i]) {
      case 'U':
        y[i + 1] = y[i] - 1;
        x[i + 1] = x[i];
        break;
      case 'D':
        y[i + 1] = y[i] + 1;
        x[i + 1] = x[i];
        break;
      case 'R':
        y[i + 1] = y[i];
        x[i + 1] = x[i] + 1;
        break;
      case 'L':
        y[i + 1] = y[i];
        x[i + 1] = x[i] - 1;
        break;
    }
  }
  int sol = 0;
  for (int i = 0; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (x[i] == x[j] && y[i] == y[j]) sol++;
  cout << sol << '\n';
  return 0;
}
