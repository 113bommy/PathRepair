#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool valid(string st, int k) {
  int ar[4] = {0};
  for (int i = 0; i < k - 1; i++) {
    int idx = st[i] - '0';
    ar[idx]++;
  }
  for (int i = k - 1; i < st.size(); i++) {
    int idx = st[i] - '0';
    ar[idx]++;
    if ((ar[1] > 0) && (ar[2] > 0) && (ar[3] > 0)) return true;
    idx = st[i - k + 1] - '0';
    ar[idx]--;
  }
  return false;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int res = INT_MAX;
    int l = 3, r = s.size();
    while (l <= r) {
      int mid = (r + l) / 2;
      if (valid(s, mid)) {
        res = min(res, mid);
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    if (res == INT_MAX) res = 0;
    cout << res << "\n";
  }
  return 0;
}
