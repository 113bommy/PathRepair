#include <bits/stdc++.h>
using namespace std;
bool DBG = false;
long long solve(int n, size_t k, const vector<int>& a, const string& s) {
  long long res = 0;
  int i = 0;
  while (i < n) {
    vector<int> values;
    values.push_back(a[i]);
    ++i;
    while (i < n && s[i - 1] == s[i]) {
      values.push_back(a[i]);
      ++i;
    }
    sort(values.rbegin(), values.rend());
    res +=
        accumulate(values.begin(), values.begin() + min(values.size(), k), 0);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  size_t k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < (int)(n); ++i) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  cout << solve(n, k, a, s) << endl;
  return 0;
}
