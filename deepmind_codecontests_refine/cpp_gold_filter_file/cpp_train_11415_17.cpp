#include <bits/stdc++.h>
using namespace std;
long long go(long long a) {
  long long t = 1, first = 0;
  while (t < a) {
    t *= 2;
    first++;
  }
  long long m = 1, second = 0;
  while (m < a) {
    m *= 3;
    second++;
  }
  int ans = 0;
  for (int i = first; i >= 0; --i) {
    for (int j = second; j >= 0; --j) {
      long long v = llround(pow(2, i)) * llround(pow(3, j));
      if (v <= a) {
        ans++;
      }
    }
  }
  return ans;
}
void solve() {
  int l, r;
  cin >> l >> r;
  cout << go(r) - go(l - 1) << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
