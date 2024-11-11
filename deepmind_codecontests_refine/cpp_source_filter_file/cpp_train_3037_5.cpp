#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (int i = 0; i < n; i += 1) cin >> a[i];
    long long int pre[n];
    pre[0] = a[0];
    for (long long int i = 1; i < n; i += 1) {
      pre[i] = a[i];
      pre[i] += pre[i - 1];
    }
    long long int q;
    cin >> q;
    for (long long int i = 0; i < q; i += 1) {
      long long int x, y;
      cin >> x >> y;
      x -= 1, y -= 1;
      long long int tmp = pre[y] - pre[x];
      tmp = tmp / 10;
      cout << tmp << "\n";
    }
  }
}
