#include <bits/stdc++.h>
using namespace std;
int i;
long long n;
long long a[100005], sum;
int cal2;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for ((i) = 0; (i) < (n); (i)++) cin >> a[i];
  sort(a, a + n);
  if (n > 1 && !a[1]) return puts("cslnb"), 0;
  for ((i) = 0; (i) < (n - 1); (i)++) {
    if (i && a[i] == a[i + 1] && a[i - 1] == a[i] - 1) return puts("cslnb"), 0;
    if (a[i] == a[i + 1]) cal2++;
  }
  if (cal2 >= 2) return puts("cslnb"), 0;
  for ((i) = 0; (i) < (n); (i)++) sum += a[i];
  sum -= n * (n - 1) / 2;
  if (sum % 2 == 0)
    return puts("cslnb"), 0;
  else
    return puts("sjfnb"), 0;
  return 0;
}
