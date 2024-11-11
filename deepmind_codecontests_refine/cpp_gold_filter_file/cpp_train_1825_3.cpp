#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using par = pair<ll, char>;
const int MAX = 2e5 + 10;
char cs[MAX], ct[MAX];
int ls[MAX], lt[MAX];
const int N = 3;
int MOD[N];
ll P[N][MAX];
ll S[N][MAX];
using momo = array<ll, N>;
vector<char> ct1, cs1;
vector<ll> lt1, ls1;
int n, m, n1, m1;
map<par, int> M;
void dame(momo& curr, int i) {
  for (int j = 0; j < N; j++) {
    ll t = 0;
    if (i) t = (S[j][i - 1] * P[j][m1 - 2]) % MOD[j];
    curr[j] = (S[j][i + m1 - 2 - 1] - t + MOD[j]) % MOD[j];
  }
}
int main() {
  srand(time(NULL));
  scanf("%d%d", &n, &m);
  ll curr = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d-%c", &lt[i], &ct[i]);
    if (i >= 1 && ct[i] != ct[i - 1]) {
      ct1.push_back(ct[i - 1]);
      lt1.push_back(curr);
      curr = lt[i];
    } else
      curr += lt[i];
  }
  ct1.push_back(ct[n - 1]);
  lt1.push_back(curr);
  curr = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d-%c", &ls[i], &cs[i]);
    if (i >= 1 && cs[i] != cs[i - 1]) {
      cs1.push_back(cs[i - 1]);
      ls1.push_back(curr);
      curr = ls[i];
    } else
      curr += ls[i];
  }
  cs1.push_back(cs[m - 1]);
  ls1.push_back(curr);
  n1 = lt1.size(), m1 = ls1.size();
  ll res = 0;
  if (m1 == 1) {
    for (int i = 0; i < n1; i++) {
      if (lt1[i] >= ls1[0] && ct1[i] == cs1[0]) res += lt1[i] - ls1[0] + 1;
    }
  }
  if (m1 == 2) {
    for (int i = 0; i + 1 < n1; i++) {
      if (lt1[i] >= ls1[0] && ct1[i] == cs1[0] && lt1[i + 1] >= ls1[1] &&
          ct1[i + 1] == cs1[1])
        res++;
    }
  }
  if (m1 > 2) {
    for (int i = 0; i < n1; i++) {
      M[par(lt1[i], ct1[i])] = 2;
    }
    for (int i = 0; i < m1; i++) {
      M[par(ls1[i], cs1[i])] = 2;
    }
    int cnt = 0;
    for (auto& p : M) {
      p.second = cnt;
      cnt++;
    }
    ll q = M.size();
    for (int j = 0; j < N; j++) {
      MOD[j] = 2e9 + (rand() % MAX);
      P[j][0] = 1;
      for (int i = 1; i < MAX; i++) {
        P[j][i] = (P[j][i - 1] * q) % MOD[j];
      }
    }
    momo target{0};
    for (int i = 1; i < m1 - 1; i++) {
      for (int j = 0; j < N; j++) {
        target[j] = (target[j] * q + M[par(ls1[i], cs1[i])]) % MOD[j];
      }
    }
    momo curr{0};
    for (int i = 0; i < n1; i++) {
      for (int j = 0; j < N; j++) {
        ll t = 0;
        if (i) t = S[j][i - 1];
        S[j][i] = (t * q + M[par(lt1[i], ct1[i])]) % MOD[j];
      }
    }
    for (int i = 1; i + m1 - 1 - 1 < n1; i++) {
      dame(curr, i);
      if (curr == target) {
        if (cs1[0] != ct1[i - 1] || ls1[0] > lt1[i - 1]) continue;
        if (cs1[m1 - 1] != ct1[i + m1 - 1 - 1] ||
            ls1[m1 - 1] > lt1[i + m1 - 1 - 1])
          continue;
        res++;
      }
    }
  }
  printf("%lld\n", res);
}
