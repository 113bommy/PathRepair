#include <bits/stdc++.h>
using namespace std;
const int me = 100025;
int n;
long long s;
int a[me];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++) s = (s + 1LL * a[i] * a[n - 1 - i]) % 10007;
  cout << s << endl;
  return 0;
}
