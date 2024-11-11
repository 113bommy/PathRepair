#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie();
  cout.tie();
  ios_base::sync_with_stdio(0);
  int n, a, b;
  cin >> n >> a >> b;
  for (int x = 0; x < 1000000; ++x) {
    int s = a * x;
    if (n - s < 0) {
      cout << "NO";
      return 0;
    }
    if ((n - s) % b == 0) {
      cout << "YES" << endl;
      cout << x << " " << (n - s) / b;
      return 0;
    }
  }
  cout << "NO";
}
