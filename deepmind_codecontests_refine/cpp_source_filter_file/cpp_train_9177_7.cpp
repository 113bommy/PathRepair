#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  long long int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int neg = 0;
  long long int max_neg = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= 0) {
      a[i] = -a[i] - 1;
      if (a[i] < 0) {
        neg++;
        max_neg = min(max_neg, a[i]);
      }
    } else {
      neg++;
      max_neg = max(max_neg, a[i]);
    }
  }
  if (neg % 2 != 0) {
    for (int i = 0; i < n; i++) {
      if (a[i] == max_neg) {
        a[i] = -a[i] - 1;
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  return 0;
}
