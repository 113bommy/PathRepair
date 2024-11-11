#include <bits/stdc++.h>
using namespace std;
int a[1000005], p[1000005];
int main() {
  int n;
  cin >> n;
  long long l = 0, tmp = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tmp += abs(a[i] - i);
    a[i] - i > 0 ? p[a[i] - i]++ : l++;
  }
  long long ans = tmp, id = 0;
  for (int i = 1; i < n; i++) {
    l--;
    if ((a[n - i + 1] - n - i + 1) > 0) p[a[n - i + 1] - n - i + 1]--;
    p[min(a[n - i + 1] + i - 1, 1000000)]++;
    tmp -= (n - l - 1);
    tmp += l;
    tmp -= abs(a[n - i + 1] - n);
    tmp += abs(a[n - i + 1] - 1);
    l += p[i];
    if (tmp < ans) ans = tmp, id = i;
  }
  cout << ans << ' ' << id << endl;
}
