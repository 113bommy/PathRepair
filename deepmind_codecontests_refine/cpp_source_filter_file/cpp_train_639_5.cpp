#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  long long a[m];
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  long long p = 0, q = 0, str = 0, isg = 0;
  for (int i = 0; i < m; i++) {
    while (i < m && a[i] - p < k + 1) {
      i++;
      str++;
    }
    p += str;
    if (str > 0) {
      i--;
      q++;
      str = 0;
      continue;
    }
    if (i < m && a[i] - p > k) {
      p += ((a[i] - p) / k) * k;
      i--;
    }
  }
  cout << q << endl;
}
