#include <bits/stdc++.h>
using namespace std;
int const N = 5e5 + 10;
long long ans = 0;
long long a[N];
int main() {
  int n;
  scanf("%d", &n);
  long long temp;
  int c = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &temp);
    while (c > 0 && temp > a[c] && a[c] < a[c - 1]) {
      ans += min(temp, a[c - 1]);
      c--;
    }
    c++;
    a[c] = temp;
  }
  sort(a + 1, a + 1 + c);
  for (int i = 1; i <= c - 2; i++) {
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
