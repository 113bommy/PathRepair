#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n, g, b;
    cin >> n >> g >> b;
    long long hf;
    if (n % 2 == 0)
      hf = n / 2;
    else
      hf = n / 2 + 1;
    long long tot = 0;
    if (hf % g == 0) {
      tot = hf + (hf / g - 1) * b;
    } else {
      tot = hf + (hf / g) * b;
    }
    if (tot < n) {
      tot += (n - tot);
    }
    cout << tot << endl;
  }
}
