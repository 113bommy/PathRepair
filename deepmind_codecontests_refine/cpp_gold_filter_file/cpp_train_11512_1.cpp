#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int N3 = 1e3 + 10;
const int INF = 2e9 + 10;
const int mod = 1e9 + 7;
const long long LINF = 4e18 + 10;
int n, k, a[2 * N], ans, cnt;
bool ok;
multiset<int> st;
bool over(int x) { return x >= 0; }
int main() {
  cin >> n >> k;
  a[0] = INF;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] < 0) {
      cnt++;
    }
  }
  if (cnt > k) {
    cout << "-1";
    return 0;
  } else {
    k -= cnt;
  }
  for (int i = 1; i <= n; ++i) {
    if (over(a[i]) != over(a[i - 1])) ans++;
  }
  cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (!ok) {
      if (!over(a[i])) {
        ok = 1;
      }
    } else {
      if (over(a[i])) {
        cnt++;
      } else {
        if (cnt > 0) {
          st.insert(cnt);
        }
        cnt = 0;
      }
    }
  }
  while (!st.empty()) {
    if (*st.begin() <= k) {
      k -= *st.begin();
      ans -= 2;
      st.erase(st.begin());
    } else
      break;
  }
  cnt = 0;
  for (int i = n; i > 1; i--) {
    if (over(a[i])) {
      cnt++;
    } else {
      break;
    }
  }
  if (cnt && cnt <= k) {
    k -= cnt;
    ans--;
  }
  cout << max(ans, 0);
  return 0;
}
