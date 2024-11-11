#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dx2[] = {1, -1, -1, 1, 0, 0, -1, 1};
int dy2[] = {1, -1, 1, -1, 1, -1, 0, 0};
int kmx[] = {-1, -1, 1, 1, 2, -2, 2, -2};
int kmy[] = {2, -2, 2, -2, -1, -1, 1, 1};
class Timer {
 public:
  clock_t T;
  Timer() { T = clock(); }
  ~Timer() {
    fprintf(stderr, "\n%.3f\n", double(clock() - T) / CLOCKS_PER_SEC);
  }
};
int read() {
  int x;
  scanf("%d", &x);
  return x;
}
const int N = 1e5;
int A[N], p[N], a, b, n, m, sz[N];
int find(int i) { return i == p[i] ? i : p[i] = find(p[i]); }
struct edge {
  int a, b, c;
} E[N];
int cmp(edge a, edge b) { return a.c > b.c; }
int main() {
  long long sum = 0;
  n = read();
  m = read();
  for (int i = 0; i < n; i++) {
    sz[i] = 1;
    p[i] = i;
    A[i] = read();
  }
  for (int i = 0; i < m; i++) {
    E[i].a = read() - 1;
    E[i].b = read() - 1;
    E[i].c = min(A[E[i].a], A[E[i].b]);
  }
  sort(E, E + m, cmp);
  int cnt = 0;
  int i = 0;
  while (i < m && cnt != n - 1) {
    a = find(E[i].a);
    b = find(E[i].b);
    if (a != b) {
      sum += 1ll * sz[a] * sz[b] * E[i].c;
      cnt++;
      p[a] = b;
      sz[b] += sz[a];
    }
    i++;
  }
  printf("%.9lf\n", (2.0 * sum) / (1.0 * n * (n - 1)));
  return 0;
}
