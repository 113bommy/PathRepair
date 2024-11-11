#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n;
  cin >> k;
  long long int a[n + 2];
  long long int s[n + 2];
  int i;
  a[0] = 0;
  s[0] = 0;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  s[1] = a[1];
  for (i = 2; i <= n; i++) {
    s[i] = a[i] + s[i - 1];
  }
  for (i = 1; i <= n - k + 1; i++) {
    a[i] = s[i + k - 1] - s[i - 1];
  }
  long long int maxx[n + 2];
  int maxind[n + 2];
  maxx[n - k + 1] = a[n - k + 1];
  maxind[n - k + 1] = n - k + 1;
  for (i = n - k; i >= 1; i--) {
    maxx[i] = max(a[i], maxx[i + 1]);
    if (maxx[i] == a[i]) {
      maxind[i] = i;
    } else if (maxx[i] == maxx[i + 1]) {
      maxind[i] = maxind[i + 1];
    }
  }
  long long int ma = 0;
  int y = n - k + 1;
  int a1 = 1;
  int b1 = 1;
  for (i = 1; i <= y - k; i++) {
    if (maxx[i] + maxx[i + k] > ma) {
      ma = maxx[i] + maxx[i + k];
      a1 = i;
      b1 = maxind[i + k];
    }
  }
  cout << a1 << " " << b1 << endl;
  return 0;
}
