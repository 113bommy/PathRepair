#include <bits/stdc++.h>
using namespace std;
long long xue[200005];
long long sha[200005];
int main() {
  int n, q;
  cin >> n >> q;
  long long s = 0;
  for (int i = 0; i < n; i++) {
    long long a;
    scanf("%lld", &a);
    s += a;
    xue[i] = s;
  }
  for (int i = 0; i < q; i++) scanf("%lld", &sha[i]);
  long long sum = 0;
  for (int i = 0; i < q; i++) {
    sum += sha[i];
    if (sum >= xue[n - 1]) {
      sum = 0;
      cout << n << endl;
    } else {
      int pos = upper_bound(xue, xue + n, sum) - xue;
      cout << n - pos << endl;
    }
  }
  return 0;
}
