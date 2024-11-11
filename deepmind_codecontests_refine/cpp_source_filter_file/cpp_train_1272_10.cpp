#include <bits/stdc++.h>
using namespace std;
long long int countbits(long long int n) {
  long long int c = 0;
  while (n) {
    c += n & 1;
    n >>= 1;
  }
  return c;
}
bool cmp(long long int a, long long int b) {
  if (countbits(a) == countbits(b))
    return a > b;
  else
    return countbits(a) > countbits(b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, x, c;
  cin >> n;
  vector<long long int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 32; i >= 0; i--) {
    x = -1;
    c = 0;
    for (int j = 0; j < n; j++) {
      if (v[j] & (1 << i)) {
        c++;
        x = j;
      }
    }
    if (c == 1)
      break;
    else
      x = -1;
  }
  if (x == -1) x = 0;
  cout << v[x] << " ";
  for (int i = 0; i < n; i++) {
    if (i != x) cout << v[i] << " ";
  }
  return 0;
}
