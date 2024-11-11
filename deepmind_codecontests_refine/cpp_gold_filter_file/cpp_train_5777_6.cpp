#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  if (n == 1 || n == 2)
    cout << "1\n"
         << "1";
  else if (n == 3)
    cout << "2\n"
         << "1 3";
  else {
    cout << n << "\n";
    for (i = 2; i <= n; i = i + 2) cout << i << " ";
    for (i = 1; i <= n; i = i + 2) cout << i << " ";
  }
}
