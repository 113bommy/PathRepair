#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if (a <= b) {
      cout << 1 << endl;
    } else
      cout << a / b + 1 << endl;
  }
}
