#include <bits/stdc++.h>
using namespace std;
int main(void) {
  char c[3], d[15];
  cin >> c;
  char ch = getchar();
  cin.get(d, 14);
  if (c[0] == d[0] || c[0] == d[3] || c[0] == d[6] || c[0] == d[9] ||
      c[0] == d[12])
    cout << "Yes";
  else if (c[1] == d[1] || c[1] == d[4] || c[1] == d[7] || c[1] == d[10] ||
           c[1] == d[13])
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
