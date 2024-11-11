#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int p = 2, q = 2;
  for (int i = 0; i < n - 2; i++) {
    if (p % n != 0)
      cout << p % n << " ";
    else
      cout << p << " ";
    p = p + q;
    q++;
  }
  if (p % n != 0)
    cout << p % n << endl;
  else
    cout << p << endl;
  return 0;
}
