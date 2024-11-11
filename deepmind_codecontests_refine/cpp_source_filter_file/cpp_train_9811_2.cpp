#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
const long long INF64 = 2000000000000000007;
const int eps = 10e-6;
long long solve(vector<int> one, vector<int> two, vector<int> three) {
  long long min_w = INF64;
  for (auto x : one) {
    long long b = x;
    auto a = lower_bound(two.begin(), two.end(), b);
    auto c = upper_bound(three.begin(), three.end(), b);
    if (a == two.end() || c == three.end()) continue;
    long long aa = two[a - two.begin()];
    long long cc = three[c - three.begin()];
    min_w = min(min_w, (aa - b) * (aa - b) + (b - cc) * (b - cc) +
                           (cc - aa) * (cc - aa));
  }
  return min_w;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int k, l, m;
    cin >> k >> l >> m;
    vector<int> red(k);
    vector<int> green(l);
    vector<int> blue(m);
    for (int i = 0; i < k; i++) cin >> red[i];
    for (int i = 0; i < l; i++) cin >> green[i];
    for (int i = 0; i < m; i++) cin >> blue[i];
    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());
    sort(green.begin(), green.end());
    long long ans = INF64;
    ans = min(ans, solve(red, green, blue));
    ans = min(ans, solve(red, blue, green));
    ans = min(ans, solve(green, red, blue));
    ans = min(ans, solve(green, blue, red));
    ans = min(ans, solve(blue, green, red));
    ans = min(ans, solve(blue, red, green));
    cout << ans << endl;
  }
  return 0;
}
