#include <bits/stdc++.h>
using namespace std;
long long N, M, x, y, K, ml, T, ans;
long long f[1000000], A[1000000];
const long long md = 1e9 + 7;
const long long MAXN = 1e5 + 2;
string in;
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    f[i] = 1;
  }
  ans = 1;
  for (int i = 1; i < N; i++) {
    if (A[i] > A[i - 1]) f[i] = f[i - 1] + 1;
    ans = max(ans, f[i]);
  }
  cout << ans << endl;
  return 0;
}
