#include <bits/stdc++.h>
using namespace std;
const int maxN = 200000, maxA = maxN * 10, mod = 1000000007;
int in[maxN], apd[maxA], T[maxA], P[maxA], multipleM[maxA], dcd[maxN];
inline void mult_mod(int& a, int b) { a = 1LL * a * b % mod; }
void updt(int p, int k) {
  if (k < T[p]) return;
  if (k == T[p]) {
    multipleM[p] = true;
    return;
  }
  for (; T[p] < k; T[p]++) mult_mod(P[p], p);
  multipleM[p] = false;
}
int main() {
  for (int(i) = (1); (i) < (maxN); (i)++) apd[i] = i, P[i] = 1;
  for (int i = 2; i * i < maxN; i++) {
    if (apd[i] != i) continue;
    for (int j = i * i; j < maxN; j += i) apd[j] = i;
  }
  int n;
  scanf("%d", &n);
  for (int(i) = (0); (i) < (n); (i)++) scanf("%d", in + i);
  sort(in, in + n);
  for (int i = n - 1; i >= 0; i--) {
    int a = in[i];
    if (T[a] == 0 or a == 2) {
      updt(a, 1);
      continue;
    }
    a--;
    while (a != 1) {
      int p = apd[a], c = 0;
      for (; a % p == 0; a /= p) c++;
      updt(p, c);
    }
    dcd[i] = true;
  }
  int res = 1;
  for (int(i) = (1); (i) < (maxN); (i)++) mult_mod(res, P[i]);
  bool incr = false;
  for (int i = n - 1; i >= 0; i--) {
    int a = in[i];
    if (!dcd[i]) {
      if (T[a] == 1 and !multipleM[a]) continue;
      incr = true;
      break;
    }
    bool ncs = false;
    a--;
    while (a != 1) {
      int p = apd[a], c = 0;
      for (; a % p == 0; a /= p) c++;
      if (T[p] == c and !multipleM[p]) {
        ncs = true;
        break;
      }
    }
    if (!ncs) {
      incr = true;
      break;
    }
  }
  if (incr) res = (res + 1) % mod;
  printf("%d\n", res);
  return 0;
}
