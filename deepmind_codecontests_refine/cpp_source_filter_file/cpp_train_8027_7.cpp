#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, sum = 0;
  cin >> n >> k;
  int a[n], s[k];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % k != 0) {
    cout << "No";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (sum / a[i] > k) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes" << endl;
  if (k == 1) {
    cout << n;
    return 0;
  }
  if (k == n) {
    for (int i = 0; i < k; i++) cout << sum / n << " ";
    return 0;
  }
  for (int i = 0; i < k; i++) s[i] = 0;
  int t = 0, c = 0;
  for (int i = 0; i < n; i++) {
    t += a[i];
    if ((sum / t) + (sum % t) > k)
      s[c]++;
    else if ((sum / t) + (sum % t) == k) {
      s[c]++;
      t = 0;
      c++;
    } else {
      c++;
    }
  }
  for (int i = 0; i < k; i++) {
    cout << s[i] << " ";
  }
  return 0;
}
