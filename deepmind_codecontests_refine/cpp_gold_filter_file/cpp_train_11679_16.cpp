#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int n;
struct Node {
  int p, D;
} a[N];
int pos[N], tmp[N], d[N];
vector<int> E[N], ch[N];
template <typename T>
void read(T &a) {
  a = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    a = a * 10 + c - '0';
    c = getchar();
  }
  a *= f;
}
bool cmp(Node a, Node b) { return a.D > b.D; }
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(d[i]);
    a[i] = (Node){i, d[i]};
  }
  sort(a + 1, a + n + 1, cmp);
  int A = 1, B = n;
  tmp[0] = a[n].p * 2 - 1;
  for (int i = 1; i <= n; ++i) {
    int p = a[i].p, D = a[i].D;
    int x = i + D - 1;
    if (x < n)
      E[a[x].p * 2 - 1].push_back(p * 2);
    else {
      tmp[x - n + 1] = p * 2;
      E[tmp[x - n]].push_back(p * 2);
    }
    if (i < n) E[p * 2 - 1].push_back(a[i + 1].p * 2 - 1);
  }
  for (int i = 1; i <= 2 * n; ++i) {
    if (E[i].size()) {
      for (int j = 0; j < E[i].size(); ++j) cout << i << ' ' << E[i][j] << endl;
    }
  }
  return 0;
}
