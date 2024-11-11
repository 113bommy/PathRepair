#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print(T t) {
  for (const auto &e : t) cout << e << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  long double p;
  cin >> p;
  if (p == 0) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    long double x = 1.0 * (i - 2) * (i - 1) * i / n / (n - 1) / (n - 2);
    long double x1 = 3.0 * (n - i) * (i - 1) * i / n / (n - 1) / (n - 2);
    long double x2 = 1.5 * (n - i) * (n - i - 1) * i / n / (n - 1) / (n - 2);
    if (x + x2 + x1 >= p - 1e-18) {
      cout << i;
      break;
    }
  }
  return 0;
}
