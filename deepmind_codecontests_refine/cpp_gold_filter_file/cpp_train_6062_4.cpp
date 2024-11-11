#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int i;
    int a[n];
    for (i = 0; i < n; i++) cin >> a[i];
    int sum = accumulate(a, a + n, 0);
    float avg = sum / n;
    int sum1 = accumulate(a + 1, a + n, 0);
    if (sum1 >= m - a[0])
      cout << m << endl;
    else
      cout << sum1 + a[0] << endl;
  }
}
