#include <bits/stdc++.h>
using namespace std;
long long a[100005], b[100005];
int main() {
  long long n, m, cnt1 = 0, cnt2 = 2, cnt3 = 0, cnt4 = 0;
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    if (a[i] % 2 == 0)
      cnt2++;
    else
      cnt1++;
  }
  for (long long i = 0; i < m; i++) {
    scanf("%lld", &b[i]);
    if (b[i] % 2 == 0)
      cnt4++;
    else
      cnt3++;
  }
  long long sum = min(cnt1, cnt4) + min(cnt2, cnt3);
  cout << sum << endl;
}
