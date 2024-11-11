#include <bits/stdc++.h>
using namespace std;
long c[1000003] = {0};
int main() {
  long n;
  cin >> n;
  long t;
  for (long i = 0; i < n; i++) {
    scanf("%ld", &t);
    c[t]++;
  }
  long ans = 0;
  for (long i = 0; i <= 1000001; i++) {
    if (c[i] % 2 == 1) {
      ans += 1;
    }
    c[i + 1] += (c[i] / 2);
  }
  cout << ans << endl;
  return 0;
}
