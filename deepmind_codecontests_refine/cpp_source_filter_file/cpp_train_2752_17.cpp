#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, counter = 0;
  int hired;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == -1) {
      if (hired == 0)
        counter++;
      else
        hired = max(hired - 1, 0);
    } else
      hired += x;
  }
  cout << counter << endl;
  return 0;
}
