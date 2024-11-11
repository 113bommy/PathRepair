#include <bits/stdc++.h>
using namespace std;
long long t, n, m, u, v, q, r, ql, qr, k, l, s, w, z, x, y, d, c, p;
const int N = 1e5 + 500;
const int NN = N + N + N;
const int LN = 21;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 52LL;
map<int, int> M;
vector<int> S;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    if (M[x]) continue;
    M[x] = 1;
    S.push_back(x);
  }
  sort(S.begin(), S.end());
  for (int i = 0; i < (int)(S.size()) - 2; ++i) {
    if (S[i + 2] - S[i] <= 2) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
