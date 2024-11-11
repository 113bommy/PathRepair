#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  long long ans;
  int a[10000];
  cin >> n >> m >> k;
  int need = m / ((n + 1) / 2);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n % 2 == 0 || need == 0)
    cout << 0;
  else {
    ans = a[0];
    for (int i = 0; i < n; i += 2) {
      ans = int(min(int(ans), a[i]));
    }
    long long sd;
    sd = need * k;
    cout << min(ans, sd);
  }
  return 0;
}
