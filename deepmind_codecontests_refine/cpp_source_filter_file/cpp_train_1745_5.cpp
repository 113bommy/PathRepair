#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6;
int n, m, s, k, t, ans, a[N];
int solve(int n) {
  set<int> st;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j + i <= n; ++j) {
      for (int k = 0; i + j + k <= n; ++k) {
        int l = n - i - j - k;
        int sum = i + j * 5 + k * 10 + l * 50;
        st.insert(sum);
      }
    }
  }
  return st.size();
}
int main() {
  scanf("%d", &n);
  if (n <= 30) return cout << solve(n) << endl, 0;
  return cout << 1ll * solve(30) + 49 * (n - 30) << endl, 0;
}
