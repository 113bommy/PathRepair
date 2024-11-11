#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30006;
int IN[MAXN];
int ile[MAXN];
vector<int> R;
int BAS, mod;
int FIB[MAXN];
const int PIER = 200;
struct node {
  int w, ws, ile;
  node() { w = ws = ile = 0; }
} D[1 << 16];
int fib(int a) { return FIB[max(a, 0)]; }
void update(int k) {
  while (k) {
    int le = D[2 * k].ile;
    D[k].w = (D[2 * k].w + 1LL * fib(le + 1) * D[2 * k + 1].w +
              1LL * fib(le) * D[2 * k + 1].ws) %
             mod;
    D[k].ws = (D[2 * k].ws + 1LL * fib(le + 1) * D[2 * k + 1].ws +
               1LL * fib(le) * (D[2 * k + 1].w + mod - D[2 * k + 1].ws)) %
              mod;
    D[k].ile = D[2 * k].ile + D[2 * k + 1].ile;
    ;
    k /= 2;
  }
}
inline void dodaj(int i) {
  int w = IN[i];
  ;
  ile[w]++;
  if (ile[w] > 1) return;
  w += BAS;
  D[w].w = R[IN[i]] % mod;
  D[w].ile = 1;
  ;
  update(w / 2);
  ;
}
inline void usun(int i) {
  int w = IN[i];
  ile[w]--;
  if (ile[w] >= 1) return;
  w += BAS;
  D[w].w = D[w].ile = 0;
  update(w / 2);
}
inline int wynik() { return D[1].w; }
inline bool cmp(const pair<pair<int, int>, int> &a,
                const pair<pair<int, int>, int> &b) {
  int p1 = a.first.first / PIER, p2 = b.first.first / PIER;
  if (p1 != p2) return p1 < p2;
  if (p1 & 1) return b.first.second < a.first.second;
  return a.first.second < b.first.second;
}
vector<int> sqrt_decom(vector<pair<int, int> > Z) {
  int d = Z.size();
  vector<pair<pair<int, int>, int> > Q(d);
  for (int i = 0; i < (d); ++i) Q[i] = pair<pair<int, int>, int>(Z[i], i);
  vector<int> ans(d);
  sort(Q.begin(), Q.end(), cmp);
  int p = 1, k = 0;
  for (auto it = (Q).begin(); it != (Q).end(); ++it) {
    while (p > it->first.first) dodaj(--p);
    while (k < it->first.second) dodaj(++k);
    while (p < it->first.first) usun(p++);
    while (k > it->first.second) usun(k--);
    ans[it->second] = wynik();
  }
  return ans;
}
int main() {
  int n, q;
  scanf("%d%d", &n, &mod);
  FIB[0] = 0;
  FIB[1] = 1 % mod;
  for (int i = 0; i < (MAXN - 2); ++i) FIB[i + 2] = (FIB[i] + FIB[i + 1]) % mod;
  for (int i = 0; i < (n); ++i) scanf("%d", &IN[i]);
  for (int i = 0; i < (n); ++i) R.push_back(IN[i]);
  sort((R).begin(), (R).end());
  R.resize(unique((R).begin(), (R).end()) - R.begin());
  for (int i = 0; i < (n); ++i)
    IN[i] = lower_bound((R).begin(), (R).end(), IN[i]) - R.begin();
  BAS = 1;
  while (BAS < R.size()) BAS *= 2;
  vector<pair<int, int> > Z;
  scanf("%d", &q);
  for (int i = 0; i < (q); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    Z.push_back(pair<int, int>(a, b));
  }
  vector<int> ans = sqrt_decom(Z);
  for (auto it = (ans).begin(); it != (ans).end(); ++it) printf("%d\n", *it);
  return 0;
}
