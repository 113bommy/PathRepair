#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  if (m == 3) {
    if (n == 3) {
      cout << "0 0" << endl << "0 1" << endl << "1 0" << endl;
      return 0;
    }
    if (n == 4) {
      cout << "3 0" << endl << "0 0" << endl << "0 3" << endl << "1 1" << endl;
      return 0;
    }
    cout << -1 << endl;
    return 0;
  }
  for (long long i = -m / 2; i < m - m / 2; i++)
    cout << i << " " << i * i + 1000000000 << endl;
  for (long long i = -(n - m) / 2; i < n - m - (n - m) / 2; i++)
    cout << i << " " << -i * i - 1000000000 << endl;
  return 0;
}
