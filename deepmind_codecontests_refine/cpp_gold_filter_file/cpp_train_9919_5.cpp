#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if (a < 3) {
      cout << 1 << endl;
    } else
      cout << (a - 3) / b + 2 << endl;
  }
}
