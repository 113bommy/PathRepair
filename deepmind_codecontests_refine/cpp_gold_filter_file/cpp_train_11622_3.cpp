#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long power(long long x, long long y) {
  long long temp = 1;
  while (y > 0) {
    if (y % 2 == 1) temp = (x * temp) % 1000000007;
    x = (x * x) % 1000000007;
    y = y / 2;
  }
  return temp;
}
long long n;
string st;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  set<string> ans;
  for (long long i = (long long)(1); i <= (long long)(n); i++) {
    cin >> st;
    while (1) {
      long long len = st.length(), ind = -1;
      for (long long i = (long long)(0); i <= (long long)(len - 2); i++) {
        if (st[i] == 'k' && st[i + 1] == 'h') {
          ind = i;
          break;
        }
      }
      if (ind != -1) {
        st = st.substr(0, ind) + 'h' + st.substr(ind + 2);
        continue;
      }
      for (long long i = (long long)(0); i <= (long long)(len - 1); i++) {
        if (st[i] == 'u') {
          ind = i;
          break;
        }
      }
      if (ind != -1) {
        st = st.substr(0, ind) + "oo" + st.substr(ind + 1);
        continue;
      } else
        break;
    }
    ans.insert(st);
  }
  cout << ans.size() << endl;
  return 0;
}
