#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int base, mod[2], ppow[2][MAX];
vector<int> in[15], where[15];
seed_seq seq{(uint64_t)chrono::duration_cast<chrono::nanoseconds>(
                 chrono::high_resolution_clock::now().time_since_epoch())
                 .count(),
             (uint64_t)__builtin_ia32_rdtsc()};
mt19937 mt(seq);
int myrand(int a, int b) { return uniform_int_distribution<int>(a, b)(mt); }
int add(int a, int b, int MOD) {
  int r = a + b;
  return r < MOD ? r : r - MOD;
}
int sub(int a, int b, int MOD) {
  int r = a - b;
  return r >= 0 ? r : r - MOD;
}
int mul(int a, int b, int MOD) { return 1ll * a * b % MOD; }
void prepow() {
  ppow[0][0] = 1, ppow[1][0] = 1;
  for (int i = 0; i < 2; i++)
    for (int j = 1; j < MAX; j++)
      ppow[i][j] = mul(ppow[i][j - 1], base, mod[i]);
}
struct DoubleHash {
  vector<int> suf[2];
  void prehash(vector<int> s) {
    int n = (int)s.size();
    suf[0].assign(n + 1, 0);
    suf[1].assign(n + 1, 0);
    for (int i = 0; i < 2; i++)
      for (int j = n - 1; j >= 0; j--)
        suf[i][j] = add(s[j], mul(suf[i][j + 1], base, mod[i]), mod[i]);
  }
  long long substr(int l, int r) {
    int ans[2] = {0, 0};
    for (int i = 0; i < 2; i++)
      ans[i] = sub(suf[i][l], mul(suf[i][r + 1], ppow[i][r - l + 1], mod[i]),
                   mod[i]);
    return 1ll * 1e9 * ans[0] + ans[1];
  }
};
bool is_prime(int x) {
  if (x <= 1 || (x & 1) == 0) return false;
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
int next_prime(int x) {
  for (int i = x + 1;; ++i)
    if (is_prime(i)) return i;
}
DoubleHash hashes[15];
int n, m;
bool ok(int mid, int idx) {
  if (idx + mid - 1 >= n) {
    cout << "PORRA" << endl;
    exit(0);
  }
  long long tmp = hashes[0].substr(idx, idx + mid - 1);
  for (int i = 1; i < m; i++) {
    if (where[i][in[0][idx]] + mid - 1 >= n) return false;
    if (hashes[i].substr(where[i][in[0][idx]],
                         where[i][in[0][idx]] + mid - 1) != tmp)
      return false;
  }
  return true;
}
int main() {
  clock_t start = clock();
  base = next_prime(myrand(0, 100) + MAX + 1);
  mod[0] = next_prime(myrand(0, 1e7) + 1e9);
  mod[1] = next_prime(myrand(1e7, 2e7) + 1e9);
  prepow();
  scanf("%d %d", &n, &m);
  if (m == 1) {
    printf("%lld\n", 1ll * n * (n + 1) / 2);
    return 0;
  }
  for (int i = 0; i < m; i++) {
    where[i].resize(n + 1);
    for (int j = 0; j < n; j++) {
      int x;
      scanf("%d", &x);
      in[i].push_back(x);
      where[i][x] = j;
    }
    hashes[i].prehash(in[i]);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int left = 1, right = n - i - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (ok(mid, i))
        left = mid + 1;
      else
        right = mid - 1;
    }
    if (left > 1 && !ok(left, i)) left--;
    ans += 1ll * left;
  }
  printf("%lld\n", ans);
}
