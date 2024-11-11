#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1e-11;
int n;
int a[100100];
set<pair<int, int> > st;
int ans = -999999999;
int main() {
  if (0) {
    freopen("z.in", "wt", stdout);
    cout << 20000 << endl;
    for (int i = 0; i < (20000); i++) cout << 1000000000 - 2 * i << ' ';
  }
  cout << setiosflags(ios::fixed) << setprecision(10);
  cin >> n;
  for (int i = 0; i < (n); i++) {
    cin >> a[i];
    st.insert(make_pair(a[i], i));
  }
  while (!st.empty()) {
    pair<int, int> v = (*st.begin());
    st.erase(st.begin());
    if (v.second > 0 && a[v.second - 1] > a[v.second] + 1) {
      st.erase(st.find(make_pair(a[v.second - 1], v.second - 1)));
      a[v.second - 1] = a[v.second] + 1;
      st.insert(make_pair(a[v.second - 1], v.second - 1));
    }
    if (v.second < n - 1 && a[v.second + 1] > a[v.second] + 1) {
      st.erase(st.find(make_pair(a[v.second + 1], v.second + 1)));
      a[v.second + 1] = a[v.second] + 1;
      st.insert(make_pair(a[v.second + 1], v.second + 1));
    }
  }
  for (int i = 0; i < (n); i++) {
    int d;
    if (i < n / 2)
      d = i + 1;
    else
      d = n - i;
    ans = max(ans, min(d, a[i]));
  }
  cout << ans;
  return 0;
}
