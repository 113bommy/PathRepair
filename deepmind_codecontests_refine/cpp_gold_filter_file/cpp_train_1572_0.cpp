#include <bits/stdc++.h>
using namespace std;
void run() {
  long long int n;
  cin >> n;
  vector<long long int> a;
  for (long long int i = 0; i < 2 * n; i++) {
    long long int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  long long int t = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
  long long int z = 1000000007;
  for (long long int i = 1; i <= n; i++) {
    z = min(z, (a[i + n - 1] - a[i]));
  }
  z *= a[2 * n - 1] - a[0];
  cout << min(t, z) << '\n';
}
int main() {
  long long int t = 1;
  for (long long int i = 0; i < t; i++) run();
}
