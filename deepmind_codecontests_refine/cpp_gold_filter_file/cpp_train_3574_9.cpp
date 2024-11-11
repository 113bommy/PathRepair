#include <bits/stdc++.h>
using namespace std;
clock_t begtime = clock();
void solve() {
  long long int n, x;
  cin >> n >> x;
  vector<long long int> a(n);
  for (long long int i = 0; i <= n - 1; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int pos = ((n + 1) / 2) - 1;
  int cnt = 0;
  int k = 0;
  if (a[pos] == x) {
    cout << "0";
    return;
  } else {
    if (!(binary_search(a.begin(), a.end(), x))) {
      a.push_back(x);
      sort(a.begin(), a.end());
      n++;
      cnt++;
    }
    pos = ((n + 1) / 2) - 1;
    if (a[pos] == x) {
      cout << "1";
      return;
    } else if (a[pos] > x) {
      while (a[pos] != x) {
        cnt++;
        n++;
        a.insert(a.begin(), -1);
        pos = ((n + 1) / 2) - 1;
      }
      cout << cnt;
    } else {
      while (a[pos + k] != x) {
        cnt++;
        n++;
        a.push_back(1000000007);
        pos = ((n + 1) / 2) - 1;
      }
      cout << cnt;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
