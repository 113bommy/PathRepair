#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000033;
const long long p = 10007;
string s;
int n, k;
int A[1000005], pref[1000005];
long long P[1000005], H[1000005];
void go(int ind, int end) {
  while (end <= n && s[end - ind] == s[end - 1]) end++;
  pref[ind] = end - ind;
}
void f_pref() {
  int ind = 1;
  pref[1] = -1;
  for (int i = 2; i <= n; i++) {
    int l = i - ind + 1;
    if (i < ind + pref[ind] && pref[l] + i < ind + pref[ind])
      pref[i] = pref[l];
    else {
      go(i, max(ind + pref[ind], i));
      ind = i;
    }
  }
}
void makehash() {
  P[0] = 1;
  for (int i = 1; i <= n; i++) P[i] = (P[i - 1] * p) % mod;
  for (int i = 1; i <= n; i++) H[i] = (H[i - 1] * p + (int)s[i - 1]) % mod;
}
long long has(int p, int k) {
  long long h = H[k] - (H[p - 1] * P[k - p + 1]) % mod;
  if (h < 0) h += mod;
  return h;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k >> s;
  makehash();
  f_pref();
  for (int l = 1; l * k <= n; l++)
    if (has(1, l * (k - 1)) == has(l + 1, l * k))
      A[l * k] = max(A[l * k], 1 + min(l - 1, pref[l * k + 1]));
  int tmp = 0;
  for (int i = 1; i <= n; i++) {
    tmp = max(tmp, A[i]);
    if (tmp != 0)
      cout << '1';
    else
      cout << '0';
    if (tmp != 0) tmp--;
  }
  cout << '\n';
  return 0;
}
