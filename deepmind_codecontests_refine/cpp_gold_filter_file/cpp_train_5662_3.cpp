#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long m(long long a) {
  return ((a % 1000000007) + 1000000007) % 1000000007;
}
long long p(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = m(m(res) * m(a));
    a = m(m(a) * m(a));
    b >>= 1;
  }
  return res;
}
signed main() {
  ;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  string a, b;
  cin >> a >> b;
  long long n1 = a.length(), n2 = b.length();
  if (a == b) {
    puts("YES");
    return 0;
  }
  if (n1 != n2 || n1 == 1) {
    puts("NO");
    return 0;
  }
  bool flag1 = false, flag2 = false;
  for (auto i : a) {
    if (i == '1') flag1 = true;
  }
  for (auto i : b) {
    if (i == '1') flag2 = true;
  }
  if (flag1 && flag2)
    puts("YES");
  else
    puts("NO");
  cerr << "\nTime elapsed : " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
}
