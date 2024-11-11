#include <bits/stdc++.h>
using namespace std;
long long int mod = 998244353;
const long double error = 2e-6;
const long double PI = acosl(-1);
mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count());
inline long long int MOD(long long int x, long long int m = mod) {
  long long int y = x % m;
  return (y >= 0) ? y : y + m;
}
const int inf = 1e9;
const long long int infl = 1061109567;
const int nmax = 2e6 + 10;
char A[nmax], L[nmax], R[nmax];
int lpref[nmax], rpref[nmax];
int z[nmax];
void Zalgo(char *str, int n) {
  int l = 0, r = 0;
  z[0] = 0;
  for (int i = 1; i < n; i++) {
    if (i < r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
      continue;
    }
    if (i > r) r = i;
    l = i;
    while (r < n && str[r - l] == str[r]) r++;
    z[i] = (r--) - l;
  }
}
long long int memo[nmax];
long long int add(long long int a, long long int b) {
  a += b;
  return (a >= mod) ? a - mod : a;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> A >> L >> R;
  int asz = strlen(A), lsz = strlen(L), rsz = strlen(R);
  L[lsz] = R[rsz] = '#';
  for (int i = 0; i < asz; i++) R[rsz + 1 + i] = L[lsz + 1 + i] = A[i];
  Zalgo(L, lsz + 1 + asz);
  for (int i = 0; i < asz; i++) {
    lpref[i] = z[lsz + 1 + i];
  }
  Zalgo(L, rsz + 1 + asz);
  for (int i = 0; i < asz; i++) {
    rpref[i] = z[rsz + 1 + i];
  }
  memo[0] = 1, memo[1] = mod - 1;
  for (int i = 0; i < asz; i++) {
    int lft = i + lsz, rgt = i + rsz;
    int x;
    x = lpref[i];
    if (x != lsz && A[i + x] < L[x]) lft++;
    x = rpref[i];
    if (x != rsz && A[i + x] > R[x]) rgt--;
    if (A[i] != '0') {
      if (lft <= rgt) {
        memo[lft] = add(memo[lft], memo[i]);
        memo[rgt + 1] = add(memo[rgt + 1], (memo[i] == 0) ? 0 : mod - memo[i]);
      }
    } else {
      if (L[0] == '0') {
        memo[i + 1] = add(memo[i + 1], memo[i]);
        memo[i + 2] = add(memo[i + 2], (memo[i] == 0) ? 0 : mod - memo[i]);
      }
    }
    memo[i + 1] = add(memo[i + 1], memo[i]);
  }
  cout << memo[asz] << endl;
  return 0;
}
