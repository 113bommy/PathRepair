#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int i = 1;
    int curr = 1;
    int old;
    int next;
    while (n >= curr) {
      i++;
      next = curr + 2 * (i - 1) - 1;
      old = curr;
      curr = next;
      if (n <= next - 1) break;
    }
    i--;
    if (n <= old + i - 1)
      cout << n - old + 1 << " " << i << endl;
    else
      cout << i << " " << old + 2 * i - 1 - n << endl;
  }
  return 0;
}
