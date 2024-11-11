#include <bits/stdc++.h>
using namespace std;
long long a[100005], i, p, n;
string f[100005], l[100005], ans[100005], s, t;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> f[i] >> l[i];
  }
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  ans[0] = min(f[a[0]], l[a[0]]);
  for (i = 1; i < n; i++) {
    p = a[i] - 1;
    s = min(f[p], l[p]);
    t = max(f[p], l[p]);
    if (s > ans[i - 1])
      ans[i] = s;
    else if (t > ans[i - 1])
      ans[i] = t;
    else {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
