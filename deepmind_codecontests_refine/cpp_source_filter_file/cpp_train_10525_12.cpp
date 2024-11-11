#include <bits/stdc++.h>
using namespace std;
long long int n, t, a[200001], b[200001], Min[200001], Max[200001], x[200001];
int main() {
  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    Max[i] = 300000000000000000ll;
  }
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    if (x[i] < i || x[i] < x[i - 1]) {
      cout << "No";
      return 0;
    }
    if (i < n) Max[x[i]] = a[x[i] + 1] + t - 1;
    if (x[i] == x[i - 1]) Min[i - 1] = a[i] + t;
  }
  b[n] = Max[n];
  for (int i = n - 1; i; i--) {
    b[i] = min(Max[i], b[i + 1] - 1);
    if (b[i] < Min[i]) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes"
       << "\n";
  for (int i = 1; i <= n; i++) cout << b[i] << " ";
  return 0;
}
