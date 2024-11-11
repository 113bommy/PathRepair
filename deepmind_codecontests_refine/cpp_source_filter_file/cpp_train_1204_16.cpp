#include <bits/stdc++.h>
template <typename A, typename B>
inline void umin(A &x, B y) {
  if (x > y) x = y;
}
template <typename A, typename B>
inline void umax(A &x, B y) {
  if (x < y) x = y;
}
const int N = 100005;
using namespace std;
int n, x, ans;
int cnt[N], num[N];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    num[x]++;
  }
  for (int i = 2; i < N; i++) {
    for (int j = i; j < N; j += i) cnt[i] += num[j];
    umax(ans, cnt[i]);
  }
  cout << ans;
}
