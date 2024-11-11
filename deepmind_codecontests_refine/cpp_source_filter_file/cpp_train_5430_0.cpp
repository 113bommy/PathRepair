#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m, arr[maxn];
bool check(int add) {
  int num[maxn];
  for (int i = 0; i <= n; i++) num[i] = arr[i];
  for (int i = 1; i <= n; i++) {
    if (num[i] == num[i - 1])
      continue;
    else if (num[i] < num[i - 1]) {
      if (num[i] + add >= num[i - 1])
        num[i] = num[i - 1];
      else
        return 0;
    } else {
      if (num[i] + add - m >= num[i - 1]) {
        num[i] = num[i - 1];
      }
    }
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  arr[0] = 0;
  int l = -1, r = m, mid;
  while (l < r) {
    mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  cout << r;
  return 0;
}
