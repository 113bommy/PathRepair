#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int a, b, n;
  cin >> n >> a >> b;
  for (int x = 0; x <= n / a; x++) {
    int ost = n - a * x;
    if (ost % b == 0) {
      cout << "YES" << endl;
      cout << x << " " << ost / b << endl;
      return 0;
    }
  }
  cout << "NO";
}
