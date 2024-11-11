#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> a(n + 1);
  vector<long long> b(q);
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  n++;
  for (int i = 0; i < q; i++) {
    scanf("%I64d", &b[i]);
  }
  vector<long long> pr(n);
  pr[0] = 0;
  for (int i = 1; i < n; i++) {
    pr[i] = pr[i - 1] + a[i];
  }
  int t = 0;
  for (int i = 0; i < q; i++) {
    vector<long long>::iterator it =
        upper_bound(pr.begin(), pr.end(), b[i] + t);
    if (it == pr.end()) {
      cout << n - 1 << "\n";
      t = 0;
    } else {
      cout << pr.end() - it << "\n";
      t += b[i];
    }
  }
}
