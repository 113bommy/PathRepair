#include <bits/stdc++.h>
using namespace std;
vector<long long int> v;
long long int ar[200000];
int main() {
  long long int n, i, dis = 100000000000000000, a, c = 0, num, sz;
  cin >> n >> a;
  for (i = 0; i < n; i++) cin >> ar[i];
  sort(ar, ar + n);
  if (n == 1)
    cout << 0 << endl;
  else {
    if (a <= ar[0])
      cout << (long long int)abs(a - ar[n - 2]) << endl;
    else if (a >= ar[n - 1])
      cout << (long long int)abs(a - ar[1]) << endl;
    else {
      for (i = 0; i < n; i++) {
        long long int l = i, u = i + n - 2;
        if (u >= n) break;
        dis = min(dis, (long long int)abs(a - ar[l]) +
                           (long long int)abs(ar[l] - ar[u]));
        dis = min(dis, (long long int)abs(a - ar[u]) +
                           (long long int)abs(ar[u] - ar[l]));
      }
      cout << dis << endl;
    }
  }
}
