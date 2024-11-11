#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, i;
  cin >> c;
  int a, b, minimum, maximum;
  cin >> minimum >> maximum;
  int pos = 0;
  for (i = 1; i < c; i++) {
    cin >> a >> b;
    if (a <= minimum && b >= maximum)
      pos = i + 1;
    else if (a < minimum || b > maximum)
      pos = -1;
    minimum = min(a, minimum);
    maximum = max(b, maximum);
  }
  cout << pos << endl;
  return 0;
}
