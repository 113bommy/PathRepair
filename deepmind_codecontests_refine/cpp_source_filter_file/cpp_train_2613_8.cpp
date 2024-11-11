#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int fact[2 * 100005];
long long int func() {
  fact[0] = fact[1] = 1;
  for (long long int i = 2; i < 200001; i++) {
    fact[i] = (fact[i - 1] * i) % 1000000007;
  }
  return 0;
}
set<long long int> st;
string a;
long long int c;
set<long long int>::iterator it, it1;
int main() {
  int n;
  cin >> n;
  long long int buy = -308983066;
  long long int sell = 308983066;
  long long int cnt = 0;
  long long int ans = 1;
  while (n--) {
    cin >> a >> c;
    if (a == "ADD") {
      st.insert(c);
      if (c > buy && c < sell) {
        cnt++;
      }
    } else {
      it = st.find(c);
      if (c > buy && c < sell) {
        ans = (ans * 2) % 1000000007;
      }
      if (c < buy || c > sell) {
        cout << 0 << endl;
        return 0;
      }
      it++;
      if (it == st.end()) {
        sell = 308983066;
      } else {
        sell = *it;
      }
      it--;
      if (it == st.begin()) {
        buy = 0;
      } else {
        it--;
        buy = *it;
        it++;
      }
      cnt = 0;
      st.erase(it);
    }
  }
  ans = ans * (cnt + 1) % 1000000007;
  cout << ans << endl;
}
