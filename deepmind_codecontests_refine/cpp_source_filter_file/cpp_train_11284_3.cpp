#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < int(n); ++i) cin >> a[i];
  long long sum = 0;
  long long j = 1;
  long long nn = n;
  for (int i = 0; i < int(n); ++i) {
    if (sum - (j - 1) * a[i] * (nn - j) < k) {
      cout << i + 1 << endl;
      --nn;
      continue;
    }
    sum += (j - 1) * a[j - 1];
    ++j;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
