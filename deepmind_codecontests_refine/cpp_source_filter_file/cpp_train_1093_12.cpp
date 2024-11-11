#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> s(100010, 0);
  for (int i(0); i < (n); i++) {
    cin >> s[i];
  }
  int smallest_s = -1;
  if (n == 2 * k) {
    int current_max = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
      current_max = s[i] + s[j];
      if (current_max > smallest_s) {
        smallest_s = current_max;
      }
    }
    cout << smallest_s;
    return 0;
  } else if (n < 2 * k) {
    int current_max = 0;
    int last = n;
    while (last >= 0 && n < 2 * k) {
      current_max = s[last];
      last--;
      if (current_max > smallest_s) {
        smallest_s = current_max;
      }
      n -= 1;
      k -= 1;
    }
    for (int i = 0, j = last - 1; i < j; i++, j--) {
      current_max = s[i] + s[j];
      if (current_max > smallest_s) {
        smallest_s = current_max;
      }
    }
    cout << smallest_s;
    return 0;
  } else if (n)
    return 0;
}
