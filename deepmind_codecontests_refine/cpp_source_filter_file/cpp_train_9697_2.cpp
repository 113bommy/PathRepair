#include <bits/stdc++.h>
using namespace std;
long long K;
long long sgpp[200001][4];
void csgpp() {
  sgpp[1][0] = K;
  sgpp[1][1] = K - 1;
  sgpp[1][2] = K - 1;
  sgpp[1][3] = K - 2;
  for (int k = 2; k < int(K + 1); k++) {
    sgpp[k][0] = (K * sgpp[k - 1][1]) % 998244353;
    sgpp[k][1] = ((K - 1) * sgpp[k - 1][1]) % 998244353;
    sgpp[k][2] = ((K - 1) * sgpp[k - 1][3]) % 998244353;
    sgpp[k][3] =
        ((((K - 2) * sgpp[k - 1][3]) % 998244353) + sgpp[k - 1][2]) % 998244353;
  }
}
long long sgp(int sz, int a, int b) {
  if (a > b) swap(a, b);
  if (a == -1 && b == -1) return sgpp[sz][0];
  if (a == -1) return sgpp[sz][1];
  if (a == b) return sgpp[sz][2];
  return sgpp[sz][3];
}
long long sv(vector<int> const& vi) {
  if (K == 2) {
    int p0 = -1;
    for (int i = 0; i < int(vi.size()); i++) {
      if (vi[i] == -1) continue;
      int p0h = (vi[i] == 0) ? (i % 2) : ((i + 1) % 2);
      if (p0 != -1 && p0 != p0h) return 0;
      p0 = p0h;
    }
    return (p0 == -1) ? 2 : 1;
  }
  long long ans = 1;
  int ls = -1, clen = 0;
  for (int i = 0; i < int(vi.size()); i++) {
    int x = vi[i];
    if (i > 0 && x != -1 && x == vi[i - 1]) return 0;
    if (x == -1) {
      ++clen;
      continue;
    }
    if (clen > 0) ans = (ans * sgp(clen, ls, x)) % 998244353;
    clen = 0;
    ls = x;
  }
  if (clen > 0) ans = (ans * sgp(clen, ls, -1)) % 998244353;
  return ans;
}
int main() {
  int N;
  scanf("%d%lld", &N, &K);
  csgpp();
  vector<int> a1, a2;
  for (int n = 0; n < int(N); n++) {
    int x;
    scanf("%d", &x);
    if (x != -1) --x;
    if (n % 2 == 0)
      a1.push_back(x);
    else
      a2.push_back(x);
  }
  printf("%lld\n", (sv(a1) * sv(a2)) % 998244353);
}
