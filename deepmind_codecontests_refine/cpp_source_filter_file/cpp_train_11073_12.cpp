#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  if (n < 3)
    cout << "-1\n";
  else {
    for (i = 1; i < n; i++) cout << i << " ";
    cout << n << endl;
  }
  return 0;
}
