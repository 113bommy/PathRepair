#include <bits/stdc++.h>
using namespace std;
void jabru() {
  int n;
  cin >> n;
  vector<int> v(n);
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  long long one = 0, two = 0;
  long long curr = 0;
  bool is = 0;
  for (int i = 0; i < n - 1; i++) {
    curr = 1LL * max(curr + 1LL * v[i], 1LL * v[i]);
    one = max(curr, one);
    if (v[i] >= 0) is = 1;
  }
  curr = LLONG_MIN;
  for (int i = 1; i < n; i++) {
    curr = 1LL * max(curr + 1LL * v[i], 1LL * v[i]);
    one = max(curr, one);
    if (v[i] >= 0) is = 1;
  }
  if (sum <= 0) {
    cout << "NO"
         << "\n";
    return;
  }
  if (one >= sum) {
    cout << "NO"
         << "\n";
  } else {
    cout << "YES"
         << "\n";
  }
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) jabru();
  return 0;
}
