#include <bits/stdc++.h>
using namespace std;
const long long M = 1e5 + 10, M2 = 1e6 + 10, oo = 1e9 + 7;
long long finish[120], nxt[120];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string sa, sb;
  long long a, b, ans = 0;
  cin >> a >> b >> sa >> sb;
  for (int i = 0; i < sb.length(); i++) {
    long long nx = i;
    for (int j = 0; j < sa.length(); j++) {
      if (sa[j] == sb[nx]) nx++;
      if (nx == sb.length()) {
        finish[i]++;
        nx = 0;
      }
      nxt[i] = nx;
    }
  }
  long long match = 0;
  for (int i = 0; i < a; i++) {
    ans += finish[match];
    match = nxt[match];
  }
  cout << ans / b << endl;
  return 0;
}
