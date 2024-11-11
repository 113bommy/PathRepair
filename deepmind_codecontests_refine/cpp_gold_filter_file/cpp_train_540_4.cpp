#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long a[10007];
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (k >= m) k = m - 1;
    long long ptr1 = k + 1, ptr2 = n;
    ptr1 = (ptr1 > 0 ? ptr1 : 0);
    long long over = 0;
    while (ptr1 > 0) {
      long long ans = INT_MAX;
      long long i = ptr1;
      long long count = m - k;
      vector<long long> v, b;
      while (count--) {
        v.push_back(a[i++]);
      }
      count = m - k;
      i = ptr2;
      while (count--) {
        b.push_back(a[i--]);
      }
      for (int i = 1; i <= m - k; i++) {
        ans = min(ans, max(v[m - k - i], b[i - 1]));
      }
      over = max(over, ans);
      ptr1--, ptr2--;
    }
    cout << over << endl;
  }
}
