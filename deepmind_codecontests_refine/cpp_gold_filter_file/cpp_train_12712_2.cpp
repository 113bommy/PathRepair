#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t = 0;
  cin >> n;
  vector<int> a(n, 0);
  vector<long long int> b(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i + 1] = b[i] + a[i];
  }
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++)
      if ((b[j] - b[i - 1]) > 100 * (j - i + 1) && (j - i + 1) >= t) {
        t = j - i + 1;
      }
  cout << t << endl;
  return 0;
}
