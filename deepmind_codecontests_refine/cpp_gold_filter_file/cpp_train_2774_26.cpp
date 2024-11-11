#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
long long a[MAXN];
int main() {
  long long n;
  int k;
  cin >> n >> k;
  for (int i = 1; i <= k; i++) cin >> a[i];
  long long ans = 0, ans1 = 1, ans2 = 0;
  for (int i = 1; i <= k; i++)
    if (ans < (n / a[i]) * a[i]) {
      ans = (n / a[i]) * a[i];
      ans1 = i, ans2 = n / a[i];
    }
  cout << ans1 << " " << ans2 << endl;
  return 0;
}
