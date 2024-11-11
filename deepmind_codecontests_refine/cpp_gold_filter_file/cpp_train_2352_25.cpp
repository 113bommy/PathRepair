#include <bits/stdc++.h>
using namespace std;
template <typename A>
void print(vector<A> v) {
  cout << v.size() << ": ";
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}
int main(int nargs, char **argv) {
  std::ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  m--;
  int price[100];
  for (int i = 0; i < n; ++i) {
    cin >> price[i];
  }
  int res = 0;
  int start = m;
  while (start < n) {
    if (price[start] > 0 && price[start] <= k) {
      break;
    }
    start++;
  }
  if (start == n) {
    res = 10000;
  } else {
    res = 10 * (start - m);
  }
  start = m;
  while (start >= 0) {
    if (price[start] > 0 && price[start] <= k) {
      break;
    }
    start--;
  }
  if (start != -1) {
    res = min(res, 10 * (m - start));
  }
  cout << res << endl;
  return 0;
}
