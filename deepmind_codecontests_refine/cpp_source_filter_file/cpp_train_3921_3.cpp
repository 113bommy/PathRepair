#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int N, p;
  cin >> N >> p;
  vector<long long> v(N), pfx(N);
  for (long long& x : v) {
    cin >> x;
  }
  pfx[0] = v[0];
  for (int i = 1; i < N; ++i) {
    pfx[i] = pfx[i - 1] + v[i];
  }
  long long best = 0;
  for (int i = 1; i < N - 1; ++i) {
    best = max(best, (pfx[i - 1] % p) + ((pfx[N - 1] - pfx[i - 1]) % p));
  }
  cout << best << endl;
  return 0;
}
