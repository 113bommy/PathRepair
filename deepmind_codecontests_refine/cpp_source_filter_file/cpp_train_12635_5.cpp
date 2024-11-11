#include <bits/stdc++.h>
using namespace std;
vector<long long> vec;
vector<pair<int, int> > vp;
pair<int, int> ar[600005];
long long a[100010], b[100010], cn, cp, sum;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] += abs(a[i]);
    if (a[i] < 0)
      cn++;
    else
      cp++;
  }
  if (cn == k) {
    for (int i = 0; i < k; i++) sum += b[i];
    for (int i = k; i < n; i++) sum += a[i];
    cout << sum;
    return 0;
  }
  if (cn > k) {
    for (int i = k; i < n; i++) sum += b[i];
    for (int i = 0; i < k; i++) sum += a[i];
    cout << sum;
    return 0;
  }
  if (cn < k) {
    if ((k - cn) % 2 == 0) {
      for (int i = 0; i < n; i++) sum += b[i];
      cout << sum;
      return 0;
    } else {
      sort(b, b + n);
      for (int i = 1; i < n; i++) sum += b[i];
      cout << sum - b[0];
      return 0;
    }
  }
}
