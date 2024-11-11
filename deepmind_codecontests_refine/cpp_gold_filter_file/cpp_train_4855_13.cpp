#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int t, n;
  cin >> n;
  int list[] = {1, 6, 28, 120, 496, 2016, 8128, 32640};
  for (int i = 7; i > -1; --i) {
    if (n % list[i] == 0) {
      cout << list[i] << endl;
      return 0;
    }
  }
  return 0;
}
