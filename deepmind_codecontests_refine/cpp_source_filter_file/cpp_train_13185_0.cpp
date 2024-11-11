#include <bits/stdc++.h>
using namespace std;
const long long maxN = 1 << 17, Sq = 1 << 5, B = 23,
                Mod = 1000 * 1000 * 1000 + 7;
long long P[maxN], H[maxN];
inline long long getHash(long long l, long long r) {
  return (H[r] - H[l] * P[r - l] % Mod + Mod) % Mod;
}
unordered_map<long long, vector<long long>> Li[Sq];
int32_t main() {
  string S;
  cin >> S;
  long long n = S.size();
  P[0] = 1;
  for (long long i = 0; i < n; i++) {
    H[i + 1] = (H[i] * B + S[i]) % Mod;
    P[i + 1] = (P[i] * B) % Mod;
  }
  for (long long l = 1; l < Sq; l++)
    for (long long i = 0; i + l <= n; i++)
      Li[l][getHash(i, i + l)].push_back(i);
  long long q;
  cin >> q;
  while (q--) {
    long long k, THash = 0;
    cin >> k;
    string T;
    cin >> T;
    for (long long i = 0; i < T.size(); i++) THash = (THash * B + T[i]) % Mod;
    vector<long long> St;
    if (T.size() < Sq)
      St = Li[T.size()][THash];
    else
      for (long long i = 0; i + T.size() <= n; i++)
        if (getHash(i, i + T.size()) == THash) St.push_back(i);
    long long a = n + 1;
    for (long long i = k - 1; i < St.size(); i++)
      a = min(a, St[i] - St[i - k + 1] + (long long)(T.size()));
    if (a == n + 1) a = -1;
    cout << a << "\n";
  }
}
