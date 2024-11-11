#include <bits/stdc++.h>
using namespace std;
const long long int P = 998244353, G = 3;
inline void add(int &a, int b) {
  a += b;
  if (a >= P) {
    a -= P;
  }
}
int fpow(int a, int k) {
  long long int r = 1LL;
  while (k) {
    if (k & 1) r = r * a % P;
    k >>= 1;
    if (k) a = (1LL * a * a) % P;
  }
  return int(r);
}
void NTT(vector<int> &a, int N, int dir) {
  int t = 0;
  for (int i = (0); i <= (N - 1); ++i) {
    if (t < i) swap(a[t], a[i]);
    for (int j = (N >> 1); (t ^= j) < j; j >>= 1)
      ;
  }
  for (int i = 2; i <= N; i <<= 1) {
    int wn = fpow(G, (P - 1) / i);
    for (int j = 0; j < N; j += i) {
      int w = 1;
      for (int k = 0; k < (i >> 1); k++, w = (1LL * w * wn % P)) {
        t = (1LL * w * a[j + k + (i >> 1)]) % P;
        a[j + k + (i >> 1)] = a[j + k] - t;
        a[j + k] = a[j + k] + t;
        if (a[j + k + (i >> 1)] < 0ll) a[j + k + (i >> 1)] += P;
        if (a[j + k] >= P) a[j + k] -= P;
      }
    }
  }
  if (dir == -1) {
    for (int i = (1); i <= ((N >> 1) - 1); ++i) swap(a[i], a[N - i]);
    int IN = fpow(N, P - 2);
    for (int i = (0); i <= (N - 1); ++i) a[i] = (1LL * a[i] * IN) % P;
  }
}
int N, K, k = 4;
vector<int> conv(vector<int> a) {
  a.resize(2 * k, 0);
  NTT(a, 2 * k, 1);
  for (int i = (0); i <= (2 * k - 1); ++i) a[i] = (1LL * a[i] * a[i]) % P;
  NTT(a, 2 * k, -1);
  a.resize(k, 0);
  return a;
}
pair<vector<int>, vector<int> > solve(int n) {
  if (n == 1) {
    vector<int> a(k, 0), b(k, 0);
    a[0] = 1;
    b[0] = b[1] = 1;
    return make_pair(a, b);
  }
  if (n == 2) {
    vector<int> a(k, 0), b(k, 0);
    a[0] = a[1] = 1;
    b[0] = b[2] = 1;
    b[1] = 3;
    return make_pair(a, b);
  }
  if (n & 1) {
    pair<vector<int>, vector<int> > a = solve(n - 1);
    vector<int> af = a.first, ac = a.second;
    vector<int> s(k, 0);
    for (int i = (0); i <= (k - 1); ++i) {
      s[i] = ac[i];
      if (i) {
        add(s[i], af[i - 1]);
        add(s[i], ac[i - 1]);
      }
    }
    return make_pair(a.second, s);
  }
  pair<vector<int>, vector<int> > a = solve(n / 2);
  vector<int> af = a.first, ac = a.second;
  vector<int> ax(k, 0), na(k, 0), nb(k, 0), aux1, aux2, aux3(k, 0);
  aux1 = conv(af);
  aux2 = conv(ac);
  for (int i = (0); i <= (k - 1); ++i) {
    nb[i] = aux2[i];
    if (i) add(nb[i], aux1[i - 1]);
  }
  for (int i = (1); i <= (k - 1); ++i) {
    ax[i - 1] = ac[i];
    add(ax[i - 1], P - af[i]);
    add(ax[i - 1], P - af[i - 1]);
  }
  ax = conv(ax);
  for (int i = (0); i <= (k - 1); ++i) {
    aux3[i] = aux1[i];
    if (i) add(aux3[i], ax[i - 1]);
  }
  na[0] = 1LL;
  for (int i = (1); i <= (k - 1); ++i) {
    na[i] = nb[i];
    add(na[i], P - na[i - 1]);
    add(na[i], P - aux3[i - 1]);
  }
  return make_pair(na, nb);
}
int main() {
  scanf("%d %d", &N, &K);
  while (k < K) k <<= 1;
  vector<int> sol = solve(N).second;
  for (int i = (1); i <= (K); ++i) {
    if (((int)(sol).size()) > i)
      printf("%d\n", sol[i]);
    else
      puts("0");
  }
  return 0;
}
