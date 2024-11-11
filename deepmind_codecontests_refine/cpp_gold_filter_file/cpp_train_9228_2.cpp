#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int(i) = 0; (i) < (n); (i)++) cin >> a[i];
  int dif = 1;
  for (int(i) = 0; (i) < (n - 1); (i)++) {
    dif = max(dif, abs(a[i + 1] - a[i]));
  }
  for (int(i) = 0; (i) < (n - 1); (i)++) {
    if (abs((a[i + 1] - 1) / dif - (a[i] - 1) / dif) +
            abs((a[i + 1] - 1) % dif - (a[i] - 1) % dif) !=
        1) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  cout << 1000000000 << " " << dif << endl;
  return 0;
}
