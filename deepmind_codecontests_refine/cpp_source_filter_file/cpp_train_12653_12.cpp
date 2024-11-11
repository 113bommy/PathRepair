#include <bits/stdc++.h>
using namespace std;
const long long N = 2 * 1e5;
long long a[N], b[N], n, ans;
deque<long long> mn, mx;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1, j = 1; i <= n; i++) {
    while (mx.size() != 0 && a[mx.back()] <= a[i]) {
      mx.pop_back();
    }
    while (mn.size() != 0 && a[mn.back()] >= b[i]) {
      mn.pop_back();
    }
    mx.push_back(i), mn.push_back(i);
    while (j <= i && a[mx.front()] - b[mn.front()] > 0) {
      j++;
      while (mx.size() != 0 && mx.front() < j) {
        mx.pop_front();
      }
      while (mn.size() != 0 && mn.front() < j) {
        mn.pop_front();
      }
    }
    if (mx.size() != 0 && mn.size() != 0 && a[mx.front()] == b[mn.front()]) {
      ans += min(mx.front(), mn.front()) - j + 1;
    }
  }
  cout << ans;
  return 0;
}
