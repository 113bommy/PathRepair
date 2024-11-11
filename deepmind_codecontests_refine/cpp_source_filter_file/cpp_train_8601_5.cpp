#include <bits/stdc++.h>
using namespace std;
int rev(long long num) {
  long long res;
  stringstream second, s1;
  string str;
  second << num;
  second >> str;
  string tem;
  tem = str;
  for (int i = str.size() - 1; i >= 0; i--) {
    tem += str[i];
  }
  s1 << tem;
  s1 >> res;
  return res;
}
int main() {
  long long k, p;
  scanf("%lld", &k);
  scanf("%lld", &p);
  long long res = 0;
  for (int i = 1; i <= k; i++) {
    res = ((res % p) + (rev(i) % p)) % p;
  }
  cout << res << endl;
  return 0;
}
