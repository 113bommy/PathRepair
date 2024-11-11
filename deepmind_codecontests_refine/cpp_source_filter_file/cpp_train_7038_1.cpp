#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z, k, w;
int A[305], B[305], pay[305], v[305], f_pay[305], val;
int FUCK[605][605], ans;
long long mod1 = 1000000007ll, mod2 = 1000000013ll;
map<pair<long long, long long>, int> M;
pair<long long, long long> hs, ht;
int a, b, f;
pair<int, int> p[305];
char s[30], t[30];
pair<long long, long long> to_hash() {
  m = strlen(s);
  long long a = 0ll, b = 0ll;
  for (int i = (0); i < (m); i++) {
    a *= 127ll;
    b *= 139ll;
    a += s[i];
    b += s[i];
    a %= mod1;
    b %= mod2;
  }
  return make_pair(a, b);
}
int main() {
  scanf("%d %d %d %d %d", &n, &a, &b, &k, &f);
  for (int i = (0); i < (n); i++) {
    scanf("%s", s);
    hs = to_hash();
    scanf("%s", s);
    ht = to_hash();
    if (!M[hs]) M[hs] = ++w;
    if (!M[ht]) M[ht] = ++w;
    A[i] = M[hs];
    B[i] = M[ht];
  }
  for (int i = (0); i < (n); i++) {
    if (i == 0 || A[i] != B[i - 1])
      pay[i] = a;
    else
      pay[i] = b;
  }
  w = 0;
  for (int i = (0); i < (n); i++) {
    if (v[i] == 1) continue;
    v[i] = 1;
    for (int j = (i); j < (n); j++) {
      if (min(A[i], B[i]) == min(A[j], B[j]) &&
          max(A[i], B[i]) == max(A[j], B[j])) {
        v[j] = 1;
        f_pay[i] += pay[j];
      }
    }
    p[w++] = make_pair(f_pay[i], i);
  }
  sort(p, p + w);
  for (int i = (w - 1); i >= (0); i--) {
    if (k >= 0 && p[i].first > f) {
      k--;
      x = p[i].second;
      FUCK[A[x]][B[x]] = FUCK[B[x]][A[x]] = 1;
      ans += f;
    }
  }
  for (int i = (0); i < (n); i++) {
    if (FUCK[A[i]][B[i]] == 1) continue;
    ans += pay[i];
  }
  printf("%d\n", ans);
  return 0;
}
