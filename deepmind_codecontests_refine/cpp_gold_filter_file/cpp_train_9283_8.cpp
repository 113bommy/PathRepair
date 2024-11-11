#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main() {
  long long n;
  cin >> n;
  vector<long long> ar(2 * n);
  if (n % 2 == 0) {
    cout << "NO\n";
    return 0;
  } else {
    cout << "YES\n";
    int cu = 0;
    for (int i = 0; i < n; i++) {
      ar[i] = (2 * i) + 1;
      ar[n + i] = (2 * i) + 2;
      if (cu % 2) swap(ar[i], ar[n + i]);
      cu++;
    }
    for (int i = 0; i < 2 * n; i++) cout << ar[i] << " ";
    return 0;
  }
  return 0;
}
