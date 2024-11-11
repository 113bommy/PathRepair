#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long a[10000];
int main(int argc, char *argv[]) {
  cin >> n >> m >> k;
  long long minvalue = 210000000;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i % 2 == 0) minvalue = min(minvalue, a[i]);
  }
  if (n % 2 == 0) {
    cout << 0 << endl;
  } else {
    long long once = n / 2 + 1;
    cout << min(minvalue, k * (m / once)) << endl;
  }
  return 0;
}
