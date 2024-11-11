#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, t, count = 0;
  cin >> n >> k >> t;
  int new_t = ((n * k * t) / 100);
  cout << endl;
  while (new_t / k != 0) {
    new_t = new_t - k;
    count++;
  }
  for (int i = 1; i <= count; i++) {
    cout << k << "  ";
  }
  if (new_t != 0) cout << new_t << "  ";
  for (int j = 1; j < n - count; j++) {
    cout << 0 << "  ";
  }
}
