#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, x, y, a, b, Max, Min, a_counter;
  cin >> t;
  while (t--) {
    cin >> x >> y >> a >> b;
    a_counter = 0;
    Max = std::max(x, y);
    Min = std::min(x, y);
    if (x != y) {
      while (Max != Min) {
        Max--;
        a_counter++;
      }
    }
    if (2 * a < b)
      cout << 2 * a * Max + a_counter * a << endl;
    else
      cout << b * Max + a_counter * a << endl;
  }
  return 0;
}
