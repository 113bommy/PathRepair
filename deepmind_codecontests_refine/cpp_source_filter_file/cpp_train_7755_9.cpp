#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000")
using namespace std;
template <typename T>
inline void read(T& x) {
  char ch;
  while (!((((ch = getchar()) >= '0') && (ch <= '9')) || (ch == '-')))
    ;
  x = ch - '0';
  while (((ch = getchar()) >= '0') && (ch <= '9')) x = x * 10 + ch - '0';
}
const int MAXN = 100100;
struct N {
  int a, b, c;
  long long sta;
  N(int a, int b, int c, long long sta) : a(a), b(b), c(c), sta(sta) {}
  bool operator<(const N& rhs) const { return a < rhs.a; }
};
vector<N> vec;
map<pair<int, int>, N> M;
map<pair<int, int>, N>::iterator it;
int num[30][4];
void dfs(int site, int B, int a, int b, int c, int ty, long long sta) {
  if (site == B + 1) {
    if (ty == 0) {
      vec.push_back(N(a, b, c, sta));
    } else {
      it = M.find(make_pair(b - a, c - a));
      if (it == M.end())
        M.insert(make_pair(make_pair(b - a, c - a), N(a, b, c, sta)));
      else
        it->second = min(it->second, N(a, b, c, sta));
    }
    return;
  }
  dfs(site + 1, B, a + num[site][1], b, c, ty, sta * 3 + 0);
  dfs(site + 1, B, a, b + num[site][2], c, ty, sta * 3 + 1);
  dfs(site + 1, B, a, b, c + num[site][3], ty, sta * 3 + 2);
}
void Output(int sta, int n) {
  if (n == 0) return;
  Output(sta / 3, n - 1);
  int tmp = sta % 3;
  if (tmp == 0)
    printf("MW\n");
  else if (tmp == 1)
    printf("LW\n");
  else if (tmp == 2)
    printf("LM\n");
}
int main() {
  int n, i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= 3; ++j) scanf("%d", &num[i][j]);
  if (n == 1) {
    for (i = 1, j = 0; i <= 3; ++i)
      if (num[1][i] == 0) j++;
    if (j <= 1) return puts("Impossible"), 0;
    for (i = 1, j = 2; i <= 3; ++i) {
      if (num[1][i] == 0) {
        if (i == 1)
          printf("L");
        else if (i == 2)
          printf("M");
        else if (i == 3)
          printf("W");
        j--;
      }
    }
    puts("");
    return 0;
  }
  dfs(1, n / 2, 0, 0, 0, 1, 0);
  dfs(n / 2 + 1, n, 0, 0, 0, 0, 0);
  int tot[4] = {0};
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= 3; ++j) tot[j] += num[i][j];
  int a, b, c;
  int Max = -2000000000;
  int p1 = -1, p2 = -1;
  for (vector<N>::iterator vit = vec.begin(); vit != vec.end(); ++vit) {
    a = tot[1] - vit->a;
    b = tot[2] - vit->b;
    c = tot[3] - vit->c;
    it = M.find(make_pair(b - a, c - a));
    if (it == M.end()) continue;
    if (Max < a - it->second.a) {
      Max = a - it->second.a, p1 = it->second.sta, p2 = vit->sta;
    }
  }
  if (p1 == -1) return printf("Impossible\n"), 0;
  Output(p1, n / 2);
  Output(p2, n - n / 2);
  return 0;
}
