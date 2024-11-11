#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long long INFL = LLONG_MAX;
int N, w, W[100100], b, B[100100], C[100100], S[100100];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int(i) = 1; (i) <= (N); (i)++) {
    cin >> C[i] >> S[i];
    if (C[i])
      B[b++] = i;
    else
      W[w++] = i;
  }
  w--, b--;
  while (w >= 0 && b >= 0) {
    int s = min(S[W[w]], S[B[b]]);
    cout << W[w] << " " << B[b] << " " << s << endl;
    S[W[w]] -= s;
    S[B[b]] -= s;
    if (S[B[b]])
      w--;
    else
      b--;
  }
  w--;
  b--;
  while (w >= 0) cout << W[w] << " " << B[0] << " " << 0 << endl, w--;
  while (b >= 0) cout << W[0] << " " << B[b] << " " << 0 << endl, b--;
}
