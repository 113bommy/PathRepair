#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000010;
vector<long long int> num;
long long int n, k, x, y, u;
long long int solve(long long int l, long long int r) {
  long long int c = lower_bound(num.begin(), num.end(), r) -
                    lower_bound(num.begin(), num.end(), l);
  if (c == 0) return x;
  if (r - l == 1) return y * c;
  long long int ans =
      min((r - l) * y * c, solve(l, (r + l) / 2) + solve((r + l) / 2, r));
  return ans;
}
int main() {
  cin >> n >> k >> x >> y;
  for (int i = 0; i < k; i++) {
    cin >> u;
    num.push_back(u);
  }
  sort(num.begin(), num.end());
  cout << solve(0, 1LL << n);
}
