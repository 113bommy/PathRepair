#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long sum = a[0];
  for (int i = 1; i < n; ++i) {
    sum += a[i];
    a[i] += a[i - 1];
  }
  if (sum % 3 != 0)
    cout << 0;
  else {
    long long tmp = sum / 3;
    long long res = 0;
    set<int> s;
    for (int i = 0; i < n - 1; ++i) {
      if (a[i] == 2 * tmp) res += s.size();
      if (a[i] == tmp) {
        s.insert(i);
      }
    }
    cout << res;
  }
  return 0;
}
