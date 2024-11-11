#include <bits/stdc++.h>
const int DIM = 205;
const int SIGMA = 26;
const long long INF = 1e18;
struct T {
  T *son[SIGMA], *bke;
  int cst, pos;
  T() {
    this->bke = NULL;
    for (int i = 0; i < SIGMA; i++) this->son[i] = NULL;
    this->cst = this->pos = 0;
  }
} *rot = new T;
long long cns[DIM][DIM], ans[DIM][DIM], axm[DIM][DIM];
int cst[DIM];
void mul(long long a[DIM][DIM], long long b[DIM][DIM], int n) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) axm[i][j] = -INF;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        axm[i][j] = std::max(axm[i][j], a[i][k] + b[k][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) a[i][j] = axm[i][j];
  return;
}
int main(int argc, const char *argv[]) {
  std::ios::sync_with_stdio(false);
  std::cin.tie();
  std::cout.tie();
  int n;
  long long m;
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> cst[i];
  int k = 0;
  rot->pos = ++k;
  for (int i = 1; i <= n; i++) {
    std::string str;
    std::cin >> str;
    T *msk = rot;
    for (char ch : str) {
      if (msk->son[ch - 'a'] == NULL) {
        msk->son[ch - 'a'] = new T;
        msk->son[ch - 'a']->pos = ++k;
      }
      msk = msk->son[ch - 'a'];
    }
    msk->cst = cst[i];
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) ans[i][j] = cns[i][j] = -INF;
    cns[i][i] = 0;
  }
  ans[1][1] = 0;
  std::deque<T *> que(1, rot);
  while (!que.empty()) {
    T *msk = que.front();
    que.pop_front();
    for (int i = 0; i < SIGMA; i++) {
      if (msk->son[i] != NULL) {
        T *aux = msk->bke;
        que.push_back(msk->son[i]);
        while (aux != NULL && aux->son[i] == NULL) aux = aux->bke;
        if (aux == NULL)
          msk->son[i]->bke = rot;
        else
          msk->son[i]->bke = aux->son[i];
        msk->son[i]->cst += msk->son[i]->bke->cst;
      }
      T *aux = msk;
      while (aux != rot && aux->son[i] == NULL) aux = aux->bke;
      if (aux->son[i] != NULL) aux = aux->son[i];
      cns[msk->pos][aux->pos] = aux->cst;
    }
  }
  for (m = m; m != 0; m /= 2) {
    if (m % 2 == 1) mul(ans, cns, k);
    mul(cns, cns, k);
  }
  long long sol = -INF;
  for (int i = 1; i <= k; i++) sol = std::max(sol, ans[1][i]);
  std::cout << sol << std::endl;
  return 0;
}
