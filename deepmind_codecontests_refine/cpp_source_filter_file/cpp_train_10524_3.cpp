#include <bits/stdc++.h>
using namespace std;
int main() {
  int sum = 0, n, i, a, b, c, d, id[1234];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a >> b >> c >> d;
    if (i == 0) sum = a + b + c + d;
    id[i] = a + b + c + d;
  }
  sort(id, id + n);
  for (i = 0; i < n; i++) {
    if (id[n - i - 1] == sum) {
      cout << n - i - 2 << endl;
      return 0;
    }
  }
  return 0;
}
