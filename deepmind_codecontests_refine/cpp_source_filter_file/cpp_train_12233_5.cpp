#include <bits/stdc++.h>
using namespace std;
void domain_expansion_() {
  int64_t p;
  cin >> p;
  vector<int> pr;
  for (int64_t i = 2; i * i <= p; i++) {
    if (p % i == 0 && p != 0) {
      while (p % i == 0) p /= i;
      pr.push_back(i);
    }
  }
  if (p) pr.push_back(p);
  int64_t ans = 1;
  for (auto x : pr) ans *= x;
  cout << ans;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int tt = 1;
  while (tt--) domain_expansion_();
}
