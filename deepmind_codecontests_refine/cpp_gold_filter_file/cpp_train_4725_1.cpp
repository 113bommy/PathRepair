#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  bool mode = true;
  bool used = false;
  char start = 'c';
  if (k > n)
    cout << "-1";
  else if (k == 1 && n > 1)
    cout << "-1";
  else {
    k -= min(2, n);
    for (int i = 1; i <= n - k; i++) {
      used = true;
      if (mode)
        putchar('a');
      else
        putchar('b');
      mode = !mode;
    }
  }
  if (used) {
    for (int i = 1; i <= k; i++) {
      putchar(start);
      start++;
    }
  }
  putchar('\n');
  return 0;
}
