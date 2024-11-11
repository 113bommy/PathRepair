#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  vector<long long> dp(n + 1);
  vector<long long> b(m);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  vector<long long> h = b;
  sort(h.begin(), h.end());
  h.push_back(1e18 + 1);
  for (int x = 0; x <= n; ++x) {
    long long left = 0;
    long long right = m;
    while (left < right) {
      long long mid = (left + right) / 2;
      long long curAns = 0;
      long long sum = h[mid];
      multiset<long long> st;
      for (int i = 0; i < n; ++i) {
        st.insert(a[i]);
        sum += a[i];
        while (sum < 0) {
          curAns++;
          sum -= *st.begin();
          st.erase(st.begin());
        }
      }
      if (curAns > x) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    dp[x] = h[right];
  }
  fflush(stdin);
  for (int i = 0; i < m; ++i) {
    long long q = b[i];
    int left = 0;
    int right = n;
    while (left < right) {
      int mid = (left + right) / 2;
      if (dp[mid] > q) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    cout << right << '\n';
  }
  return 0;
}
