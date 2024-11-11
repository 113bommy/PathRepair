#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  long long int a[n];
  long long int f[101] = {0};
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    f[a[i]]++;
  }
  sort(a, a + n);
  long long int c = f[0];
  long long int r = 0;
  long long int consumed = f[0];
  for (long long int i = 1; i <= 100; i++) {
    r = max(c * (i + 1) - consumed, (long long int)0);
    consumed += f[i];
    f[i] = max((long long int)0, f[i] - r);
    if (c >= f[i]) {
      ;
    } else {
      c = c + ceil((double)(f[i]) / (i + 1));
    }
  }
  cout << c << "\n";
  return 0;
}
