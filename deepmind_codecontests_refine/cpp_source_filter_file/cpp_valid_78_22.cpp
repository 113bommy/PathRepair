#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int max_t = a > b ? a : b;
    int min_t = a < b ? a : b;
    if (min_t < max_t / 2)
      cout << max_t % (max_t / 2 + 1) << endl;
    else
      cout << max_t % min_t << endl;
  }
}
