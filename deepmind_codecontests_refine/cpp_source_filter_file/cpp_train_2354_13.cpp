#include <bits/stdc++.h>
using namespace std;
void solve() {
  int N;
  cin >> N;
  long long A[N];
  for (auto i = 0; i <= N - 1; i++) cin >> A[i];
  int odd = 0, even = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] % 2 == 0)
      even++;
    else
      odd++;
  }
  if (odd > even)
    cout << "First\n";
  else
    cout << "Second\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}
