#include <bits/stdc++.h>
using namespace std;
void solve() {
  int N;
  cin >> N;
  vector<int64_t> A(N);
  for (auto &x : A) cin >> x;
  if (N == 1) {
    cout << 1 << " " << 1 << endl << 0 << endl;
    cout << 1 << " " << 1 << endl << 0 << endl;
    cout << 1 << " " << 1 << endl << -A[0] << endl;
  } else {
    cout << 1 << " " << N << endl;
    for (int i = 0; i < N; ++i) cout << -A[i] * N << " ";
    cout << endl;
    cout << 1 << " " << N - 1 << endl;
    for (int i = 0; i < N - 1; ++i) cout << A[i] * (N - 1) << " ";
    cout << endl;
    cout << N - 1 << " " << N - 1 << endl << A[N - 1] * (N - 1) << endl;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  T = 1;
  for (int t = 1; t <= T; ++t) solve();
  return 0;
}
