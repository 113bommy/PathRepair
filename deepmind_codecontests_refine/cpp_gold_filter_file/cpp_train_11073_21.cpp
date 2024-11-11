#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  if (n < 3)
    cout << "-1\n";
  else {
    for (i = n; i > 1; i--) cout << i << " ";
    cout << "1" << endl;
  }
  return 0;
}
