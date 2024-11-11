#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300100;
unsigned long long a[MAXN], s;
long long val[MAXN];
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> val[i] >> a[i];
    sum += val[i];
  }
  for (int k = 1; k < 63; k++) {
    long long ss = 0;
    for (int i = 0; i < n; i++)
      if (a[i] >= (1ull << (k - 1)) && a[i] < (1ull << k)) ss += val[i];
    if (ss > 0 && sum > 0) {
      s ^= (1 << (k - 1));
      for (int i = 0; i < n; i++)
        if (a[i] & (1ull << (k - 1))) val[i] *= -1;
    }
    if (ss < 0 && sum < 0) {
      s ^= (1 << (k - 1));
      for (int i = 0; i < n; i++)
        if (a[i] & (1ull << (k - 1))) val[i] *= -1;
    }
  }
  cout << s << '\n';
}
