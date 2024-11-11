#include <bits/stdc++.h>
using namespace std;
long long n, a[200005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    int i;
    set<long long> s;
    for (i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
      a[i] += i;
      s.insert((a[i] + n * 20000000000) % n);
    }
    if (s.size() == n)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
