#include <bits/stdc++.h>
using namespace std;
void run() {
  long long n, q = 1, z = 1;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] * 2 >= a[i + 1]) q++;
    z = max(z, q);
    if (a[i] * 2 < a[i + 1]) q = 1;
  }
  cout << z;
}
int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  run();
  return 0;
}
