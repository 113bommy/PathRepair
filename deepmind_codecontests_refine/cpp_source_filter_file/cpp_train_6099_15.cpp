#include <bits/stdc++.h>
using namespace std;
long long int n, a[200005], used[200005];
string s1, s2;
long long int ok(long long int x) {
  memset(used, 0, sizeof(used));
  for (long long int i = 0; i < x; i++) used[a[i]] = 1;
  long long int cnt = 0;
  for (long long int i = 0; i < n; i++) {
    if (!used[i] && s1[i] == s2[cnt]) cnt++;
    if (cnt == s2.size()) return 1;
  }
  return 0;
}
int main() {
  long long int i, j, k, nb, x, y, z;
  cin >> s1 >> s2;
  n = s1.size();
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) a[i]--;
  x = -1;
  for (z = n; z >= 1; z /= 2) {
    while (z + x <= n && ok(z + x)) x += z;
  }
  if (x != -1)
    cout << x + 1 << endl;
  else
    cout << "0";
}
