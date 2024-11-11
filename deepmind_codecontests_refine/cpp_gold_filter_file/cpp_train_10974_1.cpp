#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  if (n & 1)
    cout << (n * n + 2) / 2 << endl;
  else
    cout << (n * n) / 2 << endl;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      if ((i + j) & 1)
        cout << ".";
      else
        cout << "C";
    cout << endl;
  }
  return 0;
}
