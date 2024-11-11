#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5;
const int MAXM = 20;
int n, m, Max, h[MAXN + 10], l[MAXM + 10];
bool mp[MAXM + 2][(1 << MAXN) + 2][161052];
int now[MAXM + 10], h_ct;
vector<int> vec[MAXN + 2];
void Print() {
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      if ((now[j] & (1 << i)) > 0)
        printf("*");
      else
        printf(".");
    }
    printf("\n");
  }
}
int Pow[MAXN + 10];
int Bt[MAXN + 10];
void dfs(int x, int h_cnt, int up_lea) {
  if (mp[x][up_lea][h_cnt]) return;
  mp[x][up_lea][h_cnt] = true;
  if (x > m) {
    if (h_cnt != h_ct) return;
    Print();
    exit(0);
  }
  int Sz = vec[l[x]].size();
  for (int i = 0; i < Sz; i++) {
    int Next = h_cnt;
    bool flag = true;
    for (int j = 0; j < n; j++) {
      if ((vec[l[x]][i] & Bt[j]) && !(up_lea & Bt[j])) {
        int Now = (h_cnt / Pow[j]) % 11;
        if (Now == h[j + 1] || (m - x + 2) / 2 < h[j + 1] - Now)
          flag = false;
        else
          Next += Pow[j];
      }
      if (!flag) break;
    }
    if (!flag) continue;
    now[x] = vec[l[x]][i];
    dfs(x + 1, Next, now[x]);
  }
}
void Init() {
  for (int i = 0; i < Max; i++) {
    int Ds = 0, i_t = i << 1;
    for (int j = 1; j <= n; j++) {
      if ((i_t & (1 << j)) && !(i_t & (1 << j >> 1))) Ds++;
    }
    vec[Ds].push_back(i);
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
  for (int j = 1; j <= m; j++) scanf("%d", &l[j]);
  Max = 1 << n;
  Init();
  h_ct = 0;
  for (int i = n; i >= 1; i--) h_ct = h_ct * 11 + h[i];
  Pow[0] = 1;
  Bt[0] = 1;
  for (int i = 1; i <= n; i++) {
    Pow[i] = Pow[i - 1] * 11;
    Bt[i] = Bt[i - 1] << 1;
  }
  dfs(1, 0, 0);
  return 0;
}
