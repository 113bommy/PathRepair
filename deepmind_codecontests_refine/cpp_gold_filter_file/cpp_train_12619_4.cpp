#include <bits/stdc++.h>
using namespace std;
int NOT_OK[3][100000 + 5];
int points = 0;
int n, q;
int main() {
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    int a, b;
    cin >> a >> b;
    int x;
    if (NOT_OK[a][b] == 0)
      x = 1;
    else
      x = -1;
    if (a == 1) {
      if (NOT_OK[2][b]) points += x;
      if (NOT_OK[2][b + 1]) points += x;
      if (NOT_OK[2][b - 1]) points += x;
    } else {
      if (NOT_OK[1][b]) points += x;
      if (NOT_OK[1][b + 1]) points += x;
      if (NOT_OK[1][b - 1]) points += x;
    }
    NOT_OK[a][b] += x;
    if (points)
      cout << "no" << endl;
    else
      cout << "yes" << endl;
  }
}
