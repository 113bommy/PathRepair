#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, num;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> num;
    a[num] = i + 1;
  }
  int q, m;
  long sum1 = 0, sum2 = 0;
  cin >> q;
  while (q--) {
    cin >> m;
    sum1 += a[m];
    sum2 += n - a[m] + 1;
  }
  cout << sum1 << " " << sum2;
  return 0;
}
