#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l, k, count = 1, bigexp = 1, smallexp = 1;
  cin >> l >> k;
  l = l / k;
  vector<long long> a(l);
  vector<long long> b(l);
  for (int i = 0; i < k - 1; i++) smallexp *= 10;
  bigexp = smallexp * 10;
  for (int i = 0; i < l; i++) scanf("%lld", &a[i]);
  for (int i = 0; i < l; i++) scanf("%lld", &b[i]);
  for (int i = 0; i < l; i++) {
    long long temp = (bigexp - 1) / a[i] + 1;
    long long min = smallexp * b[i];
    long long max = smallexp * (b[i] + 1) - 1;
    if (min % a[i] == 0) {
      temp -= max / a[i] - min / a[i] + 1;
    } else {
      temp -= max / a[i] - min / a[i];
    }
    count *= temp;
    count %= 1000000007;
  }
  cout << count << endl;
}
