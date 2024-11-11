#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a[1004], diff[1004];
  cin >> n;
  diff[0] = 0;
  a[0] = 0;
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i];
    diff[i] = a[i] - a[i - 1];
  }
  double mini = -INT_MAX, maxi = INT_MAX;
  for (long long int i = 1; i <= n; i++) {
    mini = max(mini, (10 * (diff[i] + a[i - 1])) / (i + 0.0));
    maxi = min(maxi, (10 * (diff[i] + a[i - 1] + 1)) / (i + 0.0));
  }
  maxi -= 0.0000001;
  long long int mu = (mini * (n + 1) - 10 * (a[n])) / 10;
  long long int pu = (maxi * (n + 1) - 10 * (a[n])) / 10;
  if (mu == pu) {
    cout << "unique" << endl;
    cout << mu + a[n] << endl;
  } else
    cout << "not unique" << endl;
}
