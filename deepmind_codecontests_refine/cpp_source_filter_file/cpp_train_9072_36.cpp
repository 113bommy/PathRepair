#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int gs = (n / 2) + 1;
  cout << gs << "\n";
  int i = 1;
  while (i <= gs) {
    cout << i << " "
         << "1"
         << "\n";
    i++;
    n--;
  }
  int j = 2;
  while (j <= gs && n != 0) {
    cout << gs << " " << j << "\n";
    j++;
    if (n == 0) break;
  }
  return 0;
}
