#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> sets(vector<long long> &a, int start,
                                        int end) {
  int i, j = -1;
  vector<pair<long long, long long>> s;
  for (int i = start; i <= end; i++) {
    if (a[i] > 0 && j == -1) j = i;
    if (a[i] == 0 && j > -1) s.push_back({j, i - 1});
  }
  if (j > -1) s.push_back({j, end});
  return s;
}
long long solve(vector<long long> &a, long long start, long long end) {
  long long mi = *min_element(a.begin() + start, a.begin() + end);
  long long ans = end - start + 1;
  long long k = mi;
  for (int i = start; i <= end; i++) {
    a[i] = a[i] - mi;
  }
  vector<pair<long long, long long>> s = sets(a, start, end);
  if (s.size() == 0)
    return min(ans, mi);
  else {
    for (int i = 0; i < s.size(); i++)
      k = k + solve(a, s[i].first, s[i].second);
    return min(ans, k);
  }
  return 0;
}
int main() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << solve(a, 0, n - 1);
}
