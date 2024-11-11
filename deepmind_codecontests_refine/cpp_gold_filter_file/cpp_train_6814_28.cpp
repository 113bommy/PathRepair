#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long a, s = 45 * 18, i = 18;
  cin >> a;
  while (--i) s = (s * 10) % a;
  cout << (a - (s + 1) % a) % a + 1 << ' '
       << (a - (s + 1) % a) % a + 1000000000000000000;
}
