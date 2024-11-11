#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, d, e, a, Min = 1e9;
  cin >> n >> d >> e;
  for (int i = 0; i <= (n / e) / 5; i++) {
    long long int rem = n - (i * 5 * e);
    if (rem >= d) rem = rem - (rem / d * d);
    Min = min(Min, rem);
  }
  cout << Min;
  return 0;
}
