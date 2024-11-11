#include <bits/stdc++.h>
using namespace std;
int more(int n, int m, vector<int>& a) {
  long long result = 0, ans = 0, sum = n;
  vector<int> s(2 * n + 1);
  s[sum] = 1;
  for (int i = 0; i < n; ++i) {
    if (a[i] < m)
      sum--, ans -= s[sum];
    else
      ans += s[sum], sum++;
    s[sum]++;
    result += ans;
  }
  return result;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  cout << more(n, m, a) - more(n, m + 1, a);
}
