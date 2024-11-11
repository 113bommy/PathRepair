#include <bits/stdc++.h>
using namespace std;
int countbit(int n) { return (n == 0) ? 0 : (1 + countbit(n & (n - 1))); }
int lowbit(int n) { return (n ^ (n - 1)) & n; }
const double pi = acos(-1.0);
const double eps = 1e-11;
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
void checkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
void checkmax(T &a, T b) {
  if (b > a) a = b;
}
int N, M;
bool ver[2][500001], hor[2][500001];
int main() {
  scanf("%d%d", &N, &M);
  char ch;
  long long ans = 1;
  for (int i = 0; i < N; ++i) {
    getchar();
    for (int j = 0; j < M; ++j) {
      ch = getchar();
      if (ch == '.') continue;
      ver[(i % 2) ^ (ch == '1' || ch == '4')][j] = 1;
      hor[(j % 2) ^ (ch == '1' || ch == '2')][i] = 1;
    }
  }
  for (int i = 0; i < M; ++i) ans = ans * (2 - ver[0][i] - ver[1][i]) % 1000003;
  for (int i = 0; i < N; ++i) ans = ans * (2 - hor[0][i] - hor[1][i]) % 1000003;
  printf("%d\n", (int)(ans));
  return 0;
}
