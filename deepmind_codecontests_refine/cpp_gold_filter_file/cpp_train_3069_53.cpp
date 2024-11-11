#include <bits/stdc++.h>
using namespace std;
int a, b, n, v[30010], m, i, t, x, ans, w, k, j, mini, maxi;
long long int A, B, C;
char s[1010], e[] = {"qwertyuiop"}, c[] = {"asdfghjkl;"}, d[] = {"zxcvbnm,./"},
              z, *p;
int main() {
  for (j = 1; j <= 8; j++)
    for (i = 1; i <= 8; i++) {
      cin >> z;
      if (z == 'q') {
        a += 9;
      } else if (z == 'r') {
        a += 5;
      } else if (z == 'b') {
        a += 3;
      } else if (z == 'n') {
        a += 3;
      } else if (z == 'p') {
        a += 1;
      }
      if (z == 'Q') {
        b += 9;
      } else if (z == 'R') {
        b += 5;
      } else if (z == 'B') {
        b += 3;
      } else if (z == 'N') {
        b += 3;
      } else if (z == 'P') {
        b += 1;
      }
    }
  if (b > a)
    cout << "White";
  else if (a > b)
    cout << "Black";
  else
    cout << "Draw";
  return 0;
}
