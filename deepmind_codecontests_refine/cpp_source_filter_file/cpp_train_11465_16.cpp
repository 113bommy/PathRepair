#include <bits/stdc++.h>
using namespace std;
int main() {
  int d;
  cin >> d;
  for (int i = 0; i < d; ++i) {
    long long n;
    cin >> n;
    if (n * n - 4 >= 0) {
      cout << "Y " << fixed << setprecision(9) << (n + sqrt(n * n - 4 * n)) / 2
           << " " << n - (n + sqrt(n * n - 4 * n)) / 2;
      cout << "\n";
    } else {
      cout << "N\n";
    }
  }
}
