#include <bits/stdc++.h>
using namespace std;
int N, K;
int gcd(int a, int b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
void solve() {
  cin >> N >> K;
  vector<int> digits;
  vector<int> ans;
  int g = K;
  for (int i = (0); i < (N); ++i) {
    int a;
    cin >> a;
    int digit = a % K;
    if (digit == 0) continue;
    g = gcd(K, digit);
  }
  (sort((digits).begin(), (digits).end()));
  ((digits).erase(unique((digits).begin(), (digits).end()), (digits).end()));
  for (int i = 0; i * g < K; ++i) {
    ans.push_back(i * g);
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
