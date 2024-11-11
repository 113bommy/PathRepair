#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1000005, Mod = 1e9 + 7;
const int Mod1 = 1e9 + 7, Mod2 = 1e9 + 9;
char A[Nmax], B[Nmax];
int hash1[Nmax], hash2[Nmax];
int inv_hash1[Nmax], inv_hash2[Nmax];
int main() {
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  cin >> (B + 1);
  int K = strlen(B + 1);
  for (int i = 1; i <= K; ++i) {
    hash1[i] = (27LL * hash1[i - 1] + B[i] - 'a' + 1) % Mod1;
    hash2[i] = (27LL * hash2[i - 1] + B[i] - 'a' + 1) % Mod2;
  }
  for (int i = K, pw1 = 1, pw2 = 1; i > 0; --i) {
    inv_hash1[i] = (inv_hash1[i + 1] + 1LL * (B[i] - 'a' + 1) * pw1) % Mod1;
    inv_hash2[i] = (inv_hash2[i + 1] + 1LL * (B[i] - 'a' + 1) * pw2) % Mod2;
    pw1 = 27LL * pw1 % Mod1;
    pw2 = 27LL * pw2 % Mod2;
  }
  set<int> insertions;
  bool goodSol = true;
  while (M-- > 0) {
    int left;
    cin >> left;
    int right = left + K - 1;
    auto it = insertions.upper_bound(left);
    if (it != insertions.begin()) {
      --it;
      int p = *it;
      if (p + K - 1 >= left) {
        int p1 = p + K - left, p2 = K - p1 + 1;
        if (hash1[p1] != inv_hash1[p2] || hash2[p1] != inv_hash2[p2]) {
          goodSol = false;
          break;
        }
      }
    }
    it = insertions.lower_bound(left);
    if (it != insertions.end()) {
      int p = *it;
      if (p <= right) {
        int p1 = right - p + 1, p2 = K - p1 + 1;
        if (hash1[p1] != inv_hash1[p2] || hash2[p1] != inv_hash2[p2]) {
          goodSol = false;
          break;
        }
      }
    }
    insertions.insert(left);
  }
  if (goodSol == false)
    cout << "0\n";
  else {
    int ans = 1;
    for (int i = 1; i <= N; ++i) {
      auto it = insertions.upper_bound(i);
      if (it != insertions.begin()) {
        --it;
        int p = *it;
        if (p + K - 1 < i) ans = 26LL * ans % Mod;
      } else {
        ans = 26LL * ans % Mod;
      }
    }
    cout << ans << '\n';
  }
}
