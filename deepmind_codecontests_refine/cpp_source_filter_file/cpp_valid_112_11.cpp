#include <bits/stdc++.h>
using namespace std;
long long T, A[5], M;
void solve() {
  cin >> A[1] >> A[2] >> A[3] >> M;
  long long bestString = 0;
  for (long long i = 1; i <= 3; i++) bestString += A[i] - 1;
  sort(A + 1, A + 4);
  long long diff1 = A[3] - (A[1] + A[2]);
  long long diff2 = A[3] - A[1];
  long long diff3 = A[3] - A[2];
  long long worstString = min((long long)0, min(diff1, min(diff2, diff3)) - 1);
  if (M >= worstString && M <= bestString)
    cout << "YES"
         << "\n";
  else
    cout << "NO" << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  while (T--) solve();
  return 0;
}
