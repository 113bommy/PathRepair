#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k, mini = 1000009;
  cin >> n >> m >> k;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i % 2 == 0) mini = min(mini, a[i]);
  }
  if (n % 2 == 0 || m < (n + 1) / 2)
    cout << "0";
  else
    cout << min(mini, (k * (m * 2) / (n + 1)));
}
