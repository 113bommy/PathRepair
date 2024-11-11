#include <bits/stdc++.h>
using namespace std;
long long int po(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int c = po(a, b / 2);
  c = (c * c) % 1000000007;
  if (b % 2 == 1) c = (c * a) % 1000000007;
  return c;
}
int main() {
  long long int n, i;
  string s;
  cin >> n >> s;
  long long int f[4] = {0};
  for (i = 0; i < n; i++) {
    switch (s[i]) {
      case 'A':
        f[0]++;
        break;
      case 'C':
        f[1]++;
        break;
      case 'G':
        f[2]++;
        break;
      case 'T':
        f[3]++;
        break;
    }
  }
  sort(f, f + 4);
  long long int x = 1;
  for (i = 2; i >= 0; i--)
    if (f[i] == f[i + 1])
      x++;
    else
      break;
  long long int ans = po(x, n);
  cout << ans << endl;
  return 0;
}
