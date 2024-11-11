#include <bits/stdc++.h>
using namespace std;
char ch[111][111];
int n, m;
int ci = 111, cj = 111, di = -1, dj = -1;
int main() {
  cin >> n >> m;
  for (int(i) = 0; (i) < (n); ++(i))
    for (int(j) = 0; (j) < (m); ++(j)) {
      cin >> ch[i][j];
      if (ch[i][j] == '*') {
        if (i < ci) ci = i;
        if (j < cj) cj = j;
        if (i > di) di = i;
        if (j > dj) dj = j;
      }
    }
  for (int(i) = 0; (i) < (n); ++(i))
    if (i >= ci && i <= di) {
      for (int(j) = 0; (j) < (m); ++(j))
        if (j >= cj && j <= dj) cout << ch[i][j];
      cout << endl;
    }
}
