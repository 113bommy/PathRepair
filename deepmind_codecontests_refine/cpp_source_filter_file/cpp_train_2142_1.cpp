#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a, b;
  char ac = 'G', bc = 'B';
  int num = 0;
  ios_base::sync_with_stdio(false);
  cin >> n >> k >> a >> b;
  if (a > b) {
    swap(a, b);
    swap(ac, bc);
  }
  if (b > (a + 1) * (k)) {
    cout << "NO";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (b > a && num < k) {
      cout << bc;
      b--;
      num++;
    } else {
      cout << ac;
      a--;
      num = 0;
    }
  }
}
