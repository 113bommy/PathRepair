#include <bits/stdc++.h>
using namespace std;
int pw(int a, int b) {
  int res = 1;
  for (int i = 0; i < b; i++) res *= a;
  return res;
}
int main() {
  int a, b, n, i;
  cin >> a >> b >> n;
  if (a == 0 && b != 0)
    cout << "No solution";
  else if (a == 0 && b == 0)
    cout << 1;
  else if (a != 0 && b == 0)
    cout << "0";
  else {
    if (b % a)
      cout << "No solution";
    else {
      int v = b / a;
      if (v > 0) {
        for (i = 1; (int)pow(i, n) <= v; i++)
          if (v == (int)pw(i, n)) break;
        if (v == (int)pw(i, n))
          cout << i;
        else
          cout << "No solution";
      } else {
        for (i = -1; (int)pow(i, n) >= v; i--)
          if (v == (int)pw(i, n)) break;
        if (v == (int)pw(i, n))
          cout << i;
        else
          cout << "No solution";
      }
    }
  }
  return 0;
}
