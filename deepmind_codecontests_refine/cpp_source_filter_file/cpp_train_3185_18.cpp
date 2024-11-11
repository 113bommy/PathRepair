#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a;
  cin >> b;
  int res = 0;
  do {
    res++;
    a = a * 3;
    b = b * 2;
  } while (a < b);
  cout << res << endl;
  return 0;
}
