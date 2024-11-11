#include <bits/stdc++.h>
using namespace std;
int n, n1, n2, a[700007];
double sum, sum1;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  cin >> n >> n1 >> n2;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  reverse(a, a + n);
  for (int i = 0; i < min(n1, n2); i++) {
    sum += a[i];
  }
  sum /= min(n1, n2);
  for (int i = min(n1, n2); i < min(n1, n2) + max(n1, n2); i++) {
    sum1 += a[i];
  }
  sum1 /= max(n1, n2);
  setprecision(10);
  cout << sum + sum1 << endl;
}
