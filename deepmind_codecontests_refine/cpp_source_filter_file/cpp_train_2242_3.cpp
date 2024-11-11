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
const int N = 1e5 + 1;
char s[N];
int n, j[N], vis[N];
int main() {
  n = read();
  scanf("%s", s);
  for (int i = 0; i < n; i++) {
    j[i] = read();
  }
  int pos = 0;
  while (1) {
    if (pos > n || pos < 0) {
      printf("FINITE\n");
      return 0;
    }
    if (vis[pos] == N) {
      printf("INFINITE\n");
      return 0;
    }
    vis[pos]++;
    pos += s[pos] == '>' ? j[pos] : -j[pos];
  }
  return 0;
}
