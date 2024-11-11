#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
long long n, a[N], mx;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%lld", a + i);
  for (int i = 1; i <= n; i++) {
    a[i] += mx;
    mx = max(a[i], mx);
  }
  for (int i = 1; i <= n; i++) printf("%lld ", a[i]);
  cout << endl;
  return 0;
}
