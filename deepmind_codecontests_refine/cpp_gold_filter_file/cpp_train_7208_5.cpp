#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, k;
    cin >> n >> m >> k;
    long long int maximum = min(n / k, m);
    if (maximum == m) {
      cout << m << "\n";
      continue;
    }
    long long int remain = m - maximum;
    long long int nextmaximum;
    long long int prod;
    if (remain % (k - 1) == 0) {
      prod = remain / (k - 1);
    } else
      prod = remain / (k - 1) + 1;
    if (maximum == prod) {
      cout << 0 << "\n";
    } else
      cout << maximum - prod << "\n";
  }
  return 0;
}
