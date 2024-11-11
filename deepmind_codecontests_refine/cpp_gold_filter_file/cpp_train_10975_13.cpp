#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1 << 20;
int N, A[MAXN];
string S;
mt19937 rng(chrono::system_clock().now().time_since_epoch().count());
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> S;
  N = ((int)S.size());
  for (int i = 1; i <= N; ++i) A[i] = (S[i - 1] == S[N - 1] ? -1 : +1);
  for (int i = 1; i <= N; ++i) A[i] += A[i - 1];
  if (*min_element(A, A + N) == A[N] + 1) return cout << 1 << endl, 0;
  vector<int> vec;
  int mx = -1;
  for (int i = 0; i <= N; ++i)
    if (A[i] > mx) {
      vec.push_back(i);
      ++mx;
    }
  vec.push_back(N);
  int r = mx;
  for (int i = 0; i <= mx; ++i) {
    int mn = *min_element(A + vec[i], A + vec[i + 1]);
    if (mn - i <= A[N] - mx) {
      return cout << 0 << endl, 0;
    }
    r = min(r, mn - A[N] + mx - 1);
  }
  cout << max(r + 1, 0) << endl;
  return 0;
}
