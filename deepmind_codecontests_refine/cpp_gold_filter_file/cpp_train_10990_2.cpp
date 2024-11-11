#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, d, k;
  cin >> m >> d;
  if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    k = 31;
  else if (m == 2)
    k = 28;
  else
    k = 30;
  for (int i = 1; i < 7; i++)
    for (int j = i == 1 ? d : 1; j < 8; j++, k--)
      if (k == 1) {
        cout << i;
        return 0;
      }
}
