#include <bits/stdc++.h>
using namespace std;
const int MAX = 109;
char ch;
int r[MAX], c[MAX], n, m, x, y;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> ch;
      if (ch == '*') r[i]++, c[j]++;
    }
  for (int i = 0; i < max(n, m); i++) {
    if (r[i] == 1) x = i;
    if (c[i] == 1) y = i;
  }
  cout << x + 1 << " " << y + 1;
}
