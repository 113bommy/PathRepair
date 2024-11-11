#include <bits/stdc++.h>
using namespace std;
string n;
int sz;
long long mul;
long long ans;
long long powe(long long a, long long b) {
  if (!b) return 1;
  long long tmp = powe(a, b / 2);
  tmp = (tmp * tmp) % 1000000007;
  if (b % 2 == 1)
    return (tmp * a) % 1000000007;
  else
    return tmp;
}
int main() {
  cin >> n;
  sz = ((int)n.size());
  mul = powe(2, sz - 1);
  long long tp = 1;
  for (int i = sz - 1; i >= 0; i--) {
    if (n[i] == '1') {
      ans = (ans + ((tp * mul) % 1000000007)) % 1000000007;
    }
    tp = (tp * 2) % 1000000007;
  }
  cout << ans << endl;
  return 0;
}
