#include <bits/stdc++.h>
using namespace std;
int n, d;
const int MAXN = 100005;
int suf[MAXN], num[MAXN];
multiset<int> st;
int main() {
  cin >> n >> d;
  for (int i = 0; i < n; i++) cin >> num[i];
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + num[i];
    st.insert(suf[i]);
  }
  st.insert(0);
  int curr = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    if (num[i] == 0) {
      if (curr < 0) {
        int x = suf[i] - *st.begin();
        if (x > d) {
          cout << -1 << "\n";
          return 0;
        }
        curr += d - x;
        ans++;
      }
    } else
      curr += num[i];
    if (curr > d) {
      cout << -1 << "\n";
      return 0;
    }
    st.erase(st.find(suf[i]));
  }
  cout << ans << "\n";
  return 0;
}
