#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const double EPS = 1e-10;
inline double SQR(double x) { return x * x; }
inline long long SQR(long long x) { return x * x; }
inline int SQR(int x) { return x * x; }
inline double SQR3(double x) { return x * x * x; }
inline void DEBUG() { puts("jackie"); }
inline bool zero(double x) { return abs(x) < EPS; }
inline int inInt() {
  int x = 0, c;
  while ((unsigned int)((c = getchar()) - '0') >= 10) {
    if ('-' == c) return -inInt();
  }
  do {
    x = (x << 3) + (x << 1) + (c - '0');
  } while ((unsigned int)((c = getchar()) - '0') < 10);
  return x;
}
inline void outInt(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) outInt(x / 10);
  putchar((x % 10) + '0');
}
const int MAXN = 510;
int mat[MAXN][MAXN];
char board[MAXN][MAXN];
long long a[MAXN][MAXN];
int N, M, K;
long long tmp[MAXN];
bool check(int i, int j) {
  if ('1' == board[i][j] && '1' == board[i][j + 1] && '1' == board[i][j - 1] &&
      '1' == board[i - 1][j] && '1' == board[i + 1][j])
    return true;
  return false;
}
int lowbit(int x) { return x & (-x); }
void add(long long array[], int x) {
  while (x <= M + 1) {
    array[x]++;
    x += lowbit(x);
  }
}
int sum(long long array[], int x) {
  int s = 0;
  while (x > 0) {
    s += array[x];
    x -= lowbit(x);
  }
  return s;
}
int main() {
  scanf("%d %d %d", &N, &M, &K);
  for (int i = 0; i < N; i++) {
    scanf("%s", board[i]);
  }
  N -= 2, M -= 2;
  if (N < 1 || M < 1) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j < M; j++) {
      if (check(i, j)) mat[i][j] = 1;
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (mat[i][j]) {
        add(a[i], j);
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    memset(tmp, 0, sizeof(tmp));
    for (int j = i; j <= N; j++) {
      for (int k = 1; k <= M; k++) {
        tmp[k] += sum(a[j], k);
      }
      int t = 1;
      for (int k = 1; k <= M; k++) {
        while (tmp[t] - tmp[k - 1] < K && t <= M) t++;
        if (t > M) break;
        ans += M - t + 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
