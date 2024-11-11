#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a[15] = {1, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};
  if (n > 11) {
    printf("%lld\n", a[12] + (n - 12) * 49);
  } else
    cout << a[n];
}
