#include <bits/stdc++.h>
using namespace std;
long long a[] = {4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};
int main() {
  long long n;
  cin >> n;
  if (n <= 11)
    printf("%lld\n", a[n]);
  else
    printf("%lld\n", a[11] + (n - 11) * 49);
  return 0;
}
