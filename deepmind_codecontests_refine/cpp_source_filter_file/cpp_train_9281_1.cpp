#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 5e5 + 5;
int N;
int A[MAXN];
struct FW {
  long long T[MAXN];
  long long query(int p) {
    long long ret = 0;
    for (; p > 0; p -= p & -p) ret += T[p];
    return ret;
  }
  void add(int p, int w) {
    for (; p <= N; p += p & -p) T[p] += w;
  }
} L, R;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N;
  long long ans = 0;
  vector<int> v;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    ans += 1LL * ((A[i]) * (i) % mod) * (N - i + 1) % mod;
    ans %= mod;
    v.push_back(A[i]);
  }
  sort(v.begin(), v.end());
  for (int i = 1; i <= N; i++) {
    int k = (lower_bound(v.begin(), v.end(), A[i]) - v.begin()) + 1;
    R.add(k, N - i + 1);
  }
  for (int i = 1; i <= N; i++) {
    int k = (lower_bound(v.begin(), v.end(), A[i]) - v.begin()) + 1;
    ans += ((1LL * (N - i + 1) * L.query(k - 1) % mod +
             1LL * (i)*R.query(k - 1) % mod) %
            mod) *
           (1LL * A[i] % mod) % mod;
    ans %= mod;
    L.add(k, i);
    R.add(k, -(N - i + 1));
  }
  cout << ans << "\n";
}
