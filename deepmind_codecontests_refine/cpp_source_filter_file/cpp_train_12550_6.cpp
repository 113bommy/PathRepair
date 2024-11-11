#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  if (a.first > b.first)
    return (a.first < b.first);
  else if (a.first == b.first)
    return (a.second > b.second);
  else
    return true;
}
void solve() {
  long long int n, c;
  cin >> n >> c;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  long long int cnt = 1;
  for (long long int i = 1; i < n; i++) {
    if (a[i] - a[i - 1] <= c)
      cnt++;
    else
      cnt = 0;
  }
  if (n == 1)
    cout << 1;
  else
    cout << cnt + 1;
}
int main() {
  solve();
  return 0;
}
