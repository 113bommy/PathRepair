#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
const long long int INF = 2000000000;
const long long BIG = 1446803456761533460LL;
const long long int maxn = 3010;
const long long int B = 97;
long long int n;
long long int lt[maxn], rt[maxn], sz[maxn], len, first[maxn];
string S1[maxn], S2[maxn], A;
long long int lhash[maxn], powB[maxn];
long long int hash_of(long long int l, long long int r) {
  return (lhash[r] - lhash[l] * powB[r - l] % MOD + MOD) % MOD;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (long long int i = 0; i < n; ++i) cin >> S1[i];
  for (long long int i = 0; i < n; ++i) cin >> S2[i];
  for (long long int i = 0; i < n; ++i) {
    sz[i] = S1[i].size();
    while (lt[i] < sz[i] && S1[i][lt[i]] == S2[i][lt[i]]) ++lt[i];
    rt[i] = sz[i] - 1;
    while (rt[i] >= 0 && S1[i][rt[i]] == S2[i][rt[i]]) --rt[i];
  }
  long long int fst = 0;
  while (fst < n && rt[fst] == -1) ++fst;
  if (fst == n) {
    cout << "YES\na\na\n";
    return 0;
  }
  len = 0;
  while (lt[fst] + len < sz[fst]) {
    bool flag = false;
    char c = S1[fst][lt[fst] + len];
    for (long long int i = 0; i < n; ++i)
      if (rt[i] != -1) {
        if (lt[i] + len >= sz[i] || S1[i][lt[i] + len] != c) {
          flag = true;
          break;
        }
      }
    if (flag) break;
    ++len;
  }
  while (lt[fst]) {
    bool flag = false;
    char c = S1[fst][lt[fst] - 1];
    for (long long int i = 0; i < n; ++i)
      if (rt[i] != -1) {
        if (!lt[i] || S1[i][lt[i] - 1] != c) {
          flag = true;
          break;
        }
      }
    if (flag) break;
    for (long long int i = 0; i < n; ++i)
      if (rt[i] != -1) --lt[i];
    ++len;
  }
  for (long long int i = 0; i < n; ++i) {
    if (rt[i] != -1 && rt[i] + 1 > lt[i] + len) {
      cout << "NO\n";
      return 0;
    }
  }
  string A = S1[fst].substr(lt[fst], len);
  string C = S2[fst].substr(lt[fst], len);
  for (long long int i = 0; i < n; ++i) {
    if (rt[i] != -1 && C != S2[i].substr(lt[i], len)) {
      cout << "NO\n";
      return 0;
    }
  }
  long long int cur = 0;
  long long int Ahash = 0;
  powB[0] = 1;
  for (long long int i = 0; i < maxn - 1; ++i) powB[i + 1] = powB[i] * B % MOD;
  for (long long int i = 0; i < len; ++i) {
    Ahash = (Ahash * B + A[i]) % MOD;
  }
  for (long long int i = 0; i < n; ++i) {
    long long int f = -1;
    for (long long int j = 0; j < sz[i]; ++j) {
      lhash[j + 1] = (lhash[j] * B + S1[i][j]) % MOD;
      if (j + 1 >= len && hash_of(j - len + 1, j + 1) == Ahash) {
        f = j;
        break;
      }
    }
    if (f < rt[i] || rt[i] == -1 && f != -1) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  cout << A << '\n' << C << '\n';
}
