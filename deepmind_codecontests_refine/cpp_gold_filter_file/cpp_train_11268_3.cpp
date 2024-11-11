#include <bits/stdc++.h>
void print(std::vector<long long> const &input) {
  for (long long i = 0; i < input.size(); i++) {
    std::cout << input.at(i) << ' ';
  }
}
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> vec(n);
    for (long long i = 0; i < n; i++) cin >> vec[i];
    vector<long long> gap;
    long long mx = vec[0];
    long long ans = 0;
    for (long long i = 1; i < n; i++) {
      mx = max(mx, vec[i]);
      if (vec[i] != mx) gap.push_back(mx - vec[i]);
    }
    sort(gap.begin(), gap.end());
    long long r = 0;
    if (gap.size() > 0) r = gap[gap.size() - 1];
    if (r > 0) {
      ans = log2(r);
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
