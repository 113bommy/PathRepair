#include <bits/stdc++.h>
const int MOD = (int)1e9 + 7;
const int N = 100000 + 5;
char str[N];
int pw25[N], pw26[N];
int F[N], Finv[N];
int inv_pw26[N];
int inv(int x) {
  return x == 1 ? 1 : inv(MOD % x) * 1ll * (MOD - MOD / x) % MOD;
}
int comb(int a, int b) {
  if (b < 0 || b > a) return 0;
  return F[a] * 1ll * Finv[b] % MOD * Finv[a - b] % MOD;
}
void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
int main() {
  pw25[0] = pw26[0] = F[0] = Finv[0] = 1;
  for (int i = 1; i < N; ++i) {
    pw25[i] = pw25[i - 1] * 1ll * 25 % MOD;
    pw26[i] = pw26[i - 1] * 1ll * 26 % MOD;
    inv_pw26[i] = inv(pw26[i]);
    F[i] = F[i - 1] * 1ll * i % MOD;
    Finv[i] = Finv[i - 1] * inv(i) % MOD;
  }
  int m;
  scanf("%d", &m);
  int len;
  scanf("%s", str);
  len = strlen(str);
  std::vector<std::tuple<int, int, int>> vec;
  for (int _ = 0; _ < m; ++_) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%s", str);
      len = strlen(str);
    } else {
      int n;
      scanf("%d", &n);
      vec.emplace_back(len, n, _);
    }
  }
  std::sort(vec.begin(), vec.end());
  std::vector<std::pair<int, int>> answer;
  for (int i = 0, j = 0; i < (int)vec.size(); i = j++) {
    while (j < (int)vec.size() && std::get<0>(vec[i]) == std::get<0>(vec[j]))
      ++j;
    int sum = 0, p = std::get<0>(vec[i]);
    for (int k = i; k < j; ++k) {
      int l, n, id;
      std::tie(l, n, id) = vec[k];
      while (p <= n) {
        add(sum, comb(p - 1, l - 1) * 1ll * pw25[p] % MOD * inv_pw26[p] % MOD);
        p++;
      }
      answer.emplace_back(id, sum * 1ll * pw26[n] % MOD * inv(pw25[l]) % MOD);
    }
  }
  std::sort(answer.begin(), answer.end());
  for (auto &t : answer) {
    printf("%d\n", t.second);
  }
}
