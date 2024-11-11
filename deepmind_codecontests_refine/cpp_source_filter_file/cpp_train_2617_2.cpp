#include <bits/stdc++.h>
using namespace std;
long long n, k, A, B;
vector<int> a;
long long sol(long long l, long long r) {
  long long num_in =
      upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
  if (num_in == 0) return A;
  if (l == r) return B;
  return min(sol(l, (l + r) / 2) + sol((l + r) / 2 + 1, r),
             B * (r - l + 1) * num_in);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k >> A >> B;
  a.resize(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    a[i]--;
  }
  sort(a.begin(), a.end());
  cout << sol(0, (1LL << n) - 1) << endl;
  return 0;
}
