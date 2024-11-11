#include <bits/stdc++.h>
using namespace std;
long long int powm(long long int a, int b, int n) {
  long long int rm = 1;
  while (b) {
    if (b % 2) {
      rm = (rm * a) % n;
    }
    a = (a * a) % n;
    b /= 2;
  }
  return rm;
}
vector<int> I[4 * 30009];
int gdp[1010], k, Q, tq = 0, uid, second[15100], E[15100], v[15100], w[15100],
                     seg[200][1001] = {0}, id[30009], cover[15100] = {0},
                     tmp[15100] = {0}, otype, p = 10000019, q = 1000000007,
                     x[30001], ansf[30009][1001];
long long int pw[1010];
void geti(int n, int un) {
  gdp[0] = 0;
  for (int i = 1; i <= k; ++i) gdp[i] = seg[un][i];
  for (int i = 0; i < I[n].size(); ++i) {
    for (int j = k; j >= w[I[n][i]]; j--)
      gdp[j] = max(gdp[j], gdp[j - w[I[n][i]]] + v[I[n][i]]);
  }
}
void update(int n, int it, int f, int q1, int q2, int Value) {
  if (q2 < id[it] || q1 > id[f]) return;
  if (q1 < id[it] && id[f] < q2) {
    I[n].push_back(Value);
    return;
  }
  int m = (it + f) / 2;
  if (q2 <= id[m])
    update(n * 2, it, m, q1, q2, Value);
  else if (q1 > id[m])
    update(n * 2 + 1, m + 1, f, q1, q2, Value);
  else {
    update(n * 2, it, m, q1, q2, Value);
    update(n * 2 + 1, m + 1, f, q1, q2, Value);
  }
}
void insert(int n, int it, int f, int depth) {
  geti(n, depth - 1);
  for (int i = 1; i <= k; ++i) seg[depth][i] = gdp[i];
  if (it != f) {
    int m = (it + f) / 2;
    insert(n * 2, it, m, depth + 1);
    insert(n * 2 + 1, m + 1, f, depth + 1);
  } else {
    for (int i = int(1); i <= (int)k; i++) ansf[f][i] = seg[depth][i];
  }
}
int main() {
  int n;
  cin >> n >> k;
  for (int i = int(1); i <= (int)n; i++) {
    scanf("%d", &v[i]);
    ;
    scanf("%d", &w[i]);
    ;
  }
  uid = n;
  cin >> Q;
  for (int i = int(1); i <= (int)n; i++) {
    second[i] = 0;
    E[i] = Q + 1;
  }
  for (int i = int(1); i <= (int)Q; i++) {
    scanf("%d", &otype);
    ;
    if (otype == 1) {
      ++uid;
      scanf("%d", &v[uid]);
      ;
      scanf("%d", &w[uid]);
      ;
      second[uid] = i;
      E[uid] = Q + 1;
    } else if (otype == 2) {
      scanf("%d", &x[i]);
      ;
      E[x[i]] = i;
    } else {
      ++tq;
      id[tq] = i;
    }
  }
  for (int i = 1; i <= uid; ++i) {
    update(1, 1, tq, second[i], E[i], i);
  }
  if (!tq) return 0;
  insert(1, 1, tq, 1);
  long long int answer;
  int nid, ans;
  pw[0] = 1;
  for (int i = 1; i <= k; ++i) {
    pw[i] = p;
    pw[i] = (pw[i] * pw[i - 1]) % q;
  }
  for (int i = int(1); i <= (int)tq; i++) {
    answer = 0;
    for (int j = 1; j <= k; ++j) {
      answer = (answer + (1ll * ansf[i][j] * pw[j - 1]) % q) % q;
    }
    ans = answer;
    printf("%d\n", ans);
  }
  return 0;
}
