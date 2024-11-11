#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const LL INF = 1e18;
const LL one = 1900;
vector<int> primes(int n) {
  vector<int> used(n);
  vector<int> ans;
  for (int i = 2; i < n; ++i) {
    if (used[i]) {
      continue;
    }
    used[i] = 1;
    ans.push_back(i);
    for (int j = i + i; j < n; j += i) {
      used[j] = 1;
    }
  }
  return ans;
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed;
  cout.precision(12);
  auto pr = primes(1e5 + 100);
  vector<int> sum(1e5 + 100);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    for (int j = 0; pr[j] * pr[j] <= a; ++j) {
      if (a % pr[j] == 0) {
        sum[pr[j]]++;
        while (a % pr[j] == 0) {
          a /= pr[j];
        }
      }
    }
    if (a != 1) {
      sum[a]++;
    }
  }
  int ans = 1;
  for (auto p : sum) {
    ans = max(ans, p);
  }
  cout << ans << endl;
  return 0;
}
