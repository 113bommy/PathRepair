#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5 + 7;
int tt;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> tt;
  while (tt--) {
    int n, a[maxn], cnt[maxn]{};
    map<int, long long> ans;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      cnt[a[i]]++;
      ans[i] = -1;
    }
    long long len = 0;
    deque<long long> dq;
    for (int i = 0; i <= n; i++) {
      ans[i] = cnt[i] + len;
      while (cnt[i] > 1) {
        dq.push_back(i);
        cnt[i]--;
      }
      if (cnt[i] == 0) {
        if (dq.empty()) break;
        len += abs(i - dq.back());
        dq.pop_back();
      }
    }
    for (int i = 0; i <= n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}
