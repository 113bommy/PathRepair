#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100005], b[100005], c[100005];
int main() {
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    sum += -a[i] + n * b[i];
    c[i] = b[i] - a[i];
  }
  sort(c, c + n);
  for (int j = n - 1; j >= 0; j--) {
    sum += -c[j] * (j + 1);
  }
  cout << sum;
  return 0;
}
