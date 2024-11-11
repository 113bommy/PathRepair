#include <bits/stdc++.h>
using namespace std;
void solve() {
  int N;
  cin >> N;
  vector<int> A((N + 1) / 2);
  for (int &a : A) {
    cin >> a;
  }
  int X;
  cin >> X;
  vector<long long> mn(N / 2 + 1);
  long long s = 0;
  for (int i = 0; i < N / 2; i++) {
    s += X - A[i];
    mn[i + 1] = min(mn[i], s);
  }
  long long s2 = accumulate(A.begin(), A.end(), 0LL);
  for (int k = (N + 1) / 2; k <= N; k++) {
    if (s2 + mn[N - k] > 0) {
      cout << k << '\n';
      return;
    }
    s2 += X;
  }
  cout << -1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
