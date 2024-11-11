#include <bits/stdc++.h>
using namespace std;
void setIO(string NAME) {}
inline long long gI() {
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  long long flag = 1, p = 0;
  if (c == '-') flag = -1, c = getchar();
  while (c >= '0' && c <= '9') p = p * 10 + (c - '0'), c = getchar();
  return p * flag;
}
int gs(char* C) {
  char c = getchar();
  while (c == ' ' || c == '\n') c = getchar();
  int l = 0;
  while (c != ' ' && c != '\n' && c != EOF) C[l++] = c, c = getchar();
  C[l] = 0;
  return l;
}
template <class T>
void debug(const T a, const int& n) {
  for (int i = 0; i < n; ++i) printf("%d%c", a[i], (i == n - 1) ? '\n' : ' ');
}
const int inf = ~0U >> 1, maxn = 3000 + 10;
int n, sum = 0;
int f[maxn], c[maxn], s[maxn];
bool flag = 1;
struct Edge {
  int x, y, c;
  friend bool operator<(const Edge& A, const Edge& B) { return A.c < B.c; }
} E[maxn];
int find(int x) {
  if (f[x] == x) return x;
  return f[x] = find(f[x]);
}
void merge(int x, int y) {
  x = find(x), y = find(y);
  c[x] += c[y];
  s[x] += s[y];
  f[y] = x;
  if (s[x] > sum - c[x]) flag = 0;
}
int main() {
  setIO("test");
  n = gI();
  for (int i = 0; i < n - 1; ++i) {
    E[i].x = gI(), E[i].y = gI(), E[i].c = gI();
  }
  for (int i = 1; i <= n; ++i) {
    f[i] = i;
    s[i] = 1, c[i] = gI();
    sum += c[i];
  }
  sort(E, E + n - 1);
  int ans = 0;
  for (int i = 0; i < n - 1;) {
    int j;
    for (j = i; j < n - 1; ++j) {
      merge(E[j].x, E[j].y);
      if (E[j].c != E[j + 1].c) break;
    }
    if (!flag) break;
    ans = max(ans, E[j + 1].c), i = j + 1;
  }
  printf("%d\n", ans);
  return 0;
}
