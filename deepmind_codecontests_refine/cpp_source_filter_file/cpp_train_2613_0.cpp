#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int SQRTN = 320;
const int LOGN = 20;
const double PI = acos(-1);
int n, t, ans = 1, im = 1;
set<int> st;
char s['A'];
void inc() {
  ans = ans << 1;
  while (ans > 1000000007) ans -= 1000000007;
}
int main() {
  cin >> n;
  int mn = 0;
  int mx = 308983065;
  st.insert(mn);
  st.insert(mx);
  while (n--) {
    scanf(" %s %d", s, &t);
    if (s[1] == 'D')
      st.insert(t), im += (t < mx && t > mn);
    else {
      if (t > mx || t < mn) return cout << 0 << endl, 0;
      if (t > mn && t < mx) inc();
      mx = *(st.upper_bound(t));
      mn = *(--(st.lower_bound(t)));
      st.erase(t);
      im = 1;
    }
  }
  ans = (1LL * ans * im) % 1000000007;
  cout << ans << endl;
}
