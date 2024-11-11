#include <bits/stdc++.h>
using namespace std;
long double pi = 3.1415926536;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int days = 0;
  bool r = false;
  while (true) {
    days++;
    for (int i = 0; i < n; ++i) {
      a[i]--;
      if (a[i] == 0 && ((i == 0) || (i == n - 1) || (i > 0 && a[i - 1] < 0) ||
                        (i < n - 1 && a[i + 1] < 0))) {
        r = true;
        break;
      }
    }
    if (r == true) break;
  }
  cout << days;
}
