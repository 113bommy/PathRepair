#include <bits/stdc++.h>
using namespace ::std;
const int MAX = 1000;
int a[MAX], b[MAX];
int main() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
    sum += a[i];
  }
  sort(b, b + n);
  if (((b[0] == sum / n) && (b[n - 1] == sum / n))) {
    cout << "Exemplary pages.\n";
    return 0;
  }
  int mil = b[n - 1] - b[0];
  if (!(mil & 1)) {
    cout << "Unrecoverable configuration.\n";
    return 0;
  }
  int mid = (b[0] + b[n - 1]) / 2;
  b[0] = mid;
  b[n - 1] = mid;
  mid = sum / n;
  int from = 0;
  int to = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] != mid) {
      cout << "Unrecoverable configuration.\n";
      return 0;
    }
    if (a[i] < mid) {
      from = i + 1;
    }
    if (a[i] > mid) {
      to = i + 1;
    }
  }
  cout << mil / 2 << " ml. from cup #" << from << " to cup #" << to << ".\n";
  return 0;
}
