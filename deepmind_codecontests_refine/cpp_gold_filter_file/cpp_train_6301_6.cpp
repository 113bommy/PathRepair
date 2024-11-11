#include <bits/stdc++.h>
using namespace std;
long long i, j, k, p, l, m, n, c, d, f, g, t[int(2e5 + 200)], mx, mn, ans, x, y;
string s;
set<long long> st;
set<long long>::iterator it;
long long pas;
bool a[int(2e5 + 200)];
int main() {
  cin >> n >> k;
  cin >> s;
  for (int i = 1; i <= n; i++) {
    if ('1' - s[i - 1]) st.insert(i);
  }
  l = 1;
  c = 0;
  pas = (long long)(9e12);
  for (int i = 1; i <= n; i++) {
    t[i] = c;
    c += '1' - s[i - 1];
    if (c - t[l] <= k) continue;
    while (c - t[l] > k) l++;
    l--;
    it = st.lower_bound((i + l) / 2);
    pas = min(pas, max(i - (*it), (*it) - l));
    if (it != --st.end()) {
      it++;
      pas = min(pas, max(i - (*it), (*it) - l));
      it--;
    }
    if (it != st.begin()) it--;
    pas = min(pas, max(i - (*it), (*it) - l));
  }
  cout << pas;
  return 0;
}
