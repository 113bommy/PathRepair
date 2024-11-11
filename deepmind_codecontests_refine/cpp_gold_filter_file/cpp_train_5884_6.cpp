#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long a, b, c, i = -1, j = -1, k = 0, ans = 0;
  cin >> a >> b;
  c = a;
  while (c) {
    i++;
    if (((c & 1) + 1) % 2) j = i;
    c >>= 1;
  }
  if (j != -1)
    c = (1LL << i + 1) - 1 - (1LL << j);
  else {
    j = i;
    i++;
    c = (1LL << i + 1) - 1 - (1LL << j);
  }
  k = j;
  while (c <= b) {
    if (k == -1) {
      j = i;
      k = j;
      i++;
      c = (1LL << i + 1) - 1 - (1LL << j);
    } else {
      ans++;
      c += (1LL << k) - (1LL << k - 1);
      k--;
    }
  }
  cout << ans << endl;
}
