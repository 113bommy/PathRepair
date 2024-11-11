#include <bits/stdc++.h>
using namespace std;
int n;
int na, nb, nc, nd;
char clown[5000 + 100], acrobat[5000 + 10];
void PRINT(int a, int b, int c, int d) {
  for (int i = 1; i < n + 1; i++) {
    if (clown[i] && acrobat[i] && d) {
      d--;
      cout << i << " ";
    }
    if (clown[i] && !acrobat[i] && c) {
      c--;
      cout << i << " ";
    }
    if (!clown[i] && acrobat[i] && b) {
      b--;
      cout << i << " ";
    }
    if (!clown[i] && !acrobat[i] && a) {
      a--;
      cout << i << " ";
    }
  }
  cout << '\n';
}
void process() {
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    cin >> clown[i];
    clown[i] -= '0';
  }
  for (int i = 1; i < n + 1; i++) {
    cin >> acrobat[i];
    acrobat[i] -= '0';
  }
  for (int i = 1; i < n + 1; i++) {
    if (clown[i] && acrobat[i])
      nd++;
    else if (clown[i] && !acrobat[i])
      nc++;
    else if (!clown[i] && acrobat[i])
      nb++;
    else
      na++;
  }
  for (int b = 0; b < nb; b++) {
    for (int c = 0; c < nc; c++) {
      int d = (nb + nd - b - c) / 2;
      int a = n / 2 - b - c - d;
      if (d >= 0 && d <= nd && a >= 0 && a <= na) {
        if (a + b + c + d == n / 2 && c + d == nb - b + nd - d) {
          PRINT(a, b, c, d);
          return;
        }
      }
    }
  }
  cout << "-1" << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  process();
  return 0;
}
