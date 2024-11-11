#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  long long n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k, s = v.size();
    cin >> k;
    while (s > 1 && v[s - 1] <= k && v[s - 1] <= v[s - 2])
      ans += min(k, v[s - 2]), v.pop_back(), s--;
    v.push_back(k);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < (int)v.size() - 2; i++) ans += v[i];
  cout << ans << endl;
  return 0;
}
