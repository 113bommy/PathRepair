#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
int n;
std::vector<int> b;
std::vector<int> a;
void yes() {
  printf("YES\n");
  for (auto x : a) printf("%d ", x);
  exit(0);
}
void no() {
  printf("NO\n");
  exit(0);
}
void fill(int f) {
  for (int i = f; i < n; i++) {
    a.push_back(b[i] - a[0]);
  }
}
int w[15 * 1000000];
void get(int mask1, int mask2) {
  int sm = mask1 & mask2;
  mask1 ^= sm;
  mask2 ^= sm;
  int l = __builtin_popcount(mask1);
  std::vector<int> a1, a2;
  std::vector<int> fr;
  for (int i = 0; i < min(30, n); i++) {
    if ((1 << i) & mask1)
      a1.push_back(b[i]);
    else if ((1 << i) & mask2)
      a2.push_back(b[i]);
    else
      fr.push_back(b[i]);
  }
  for (int i = 2 * l; i < min(30, n); i++) b[i] = fr[i - 2 * l];
  std::vector<int> zp;
  for (int i = 0; i < l; i++) {
    zp.push_back(a1[i]);
    zp.push_back(a2[i]);
  }
  int last = 0;
  for (int i = 0; i < 2 * l; i++) {
    a.push_back(zp[i] - last);
    last = a.back();
  }
  fill(2 * l);
  yes();
}
int main() {
  scanf("%d", &n);
  b.resize(n);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  for (int i = 0; i < n; i++)
    if (b[i] % 2 == 0) swap(b[0], b[i]);
  if (n == 2) {
    if (b[0] != b[1])
      no();
    else {
      a.push_back(0);
      a.push_back(b[0]);
      yes();
    }
  }
  if (b[0] % 2 == 0) {
    if (n >= 4) {
      if (b[1] % 2 == b[3] % 2) swap(b[2], b[3]);
      if (b[2] % 2 == b[3] % 2) swap(b[1], b[3]);
    }
    if (b[1] % 2 == b[2] % 2) {
      int sum = b[0] + b[1] + b[2];
      for (int i = 0; i < 3; i++) a.push_back((sum - 2 * b[i]) / 2);
      fill(4);
      yes();
    }
    if (b[2] == b[1]) swap(b[2], b[0]);
    if (b[2] == b[0]) swap(b[1], b[2]);
    if (b[0] == b[1]) {
      a.push_back(0);
      a.push_back(b[0]);
      fill(2);
      yes();
    }
  }
  int tbit = min(n / 2, 14);
  const int A = 1000000;
  for (int i = 0; i < tbit * A + 1; i++) w[i] = -1;
  for (int mask = 0; mask < 1 << (min(n, 28)); mask++) {
    if (__builtin_popcount(mask) == tbit) {
      int cur = 0;
      for (int bit = 0; bit < min(n, 28); bit++)
        if (mask & (1 << bit)) cur += b[bit];
      if (w[cur] != -1)
        get(w[cur], mask);
      else
        w[cur] = mask;
    }
  }
  no();
}
