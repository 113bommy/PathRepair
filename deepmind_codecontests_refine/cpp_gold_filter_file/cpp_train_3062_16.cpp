#include <bits/stdc++.h>
template <class K>
inline bool umax(K& a, K b) {
  return a < b ? a = b, true : false;
}
template <class K>
inline bool umin(K& a, K b) {
  return a > b ? a = b, true : false;
}
template <class K>
inline void read(K& first) {
  char c = getchar();
  K f = +1;
  for (first = 0; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) first = first * 10 + c - '0';
  first = first * f;
}
template <class K>
inline void write(K first) {
  static int fout[20], top;
  if (first < 0) putchar('-'), first = -first;
  do fout[top++] = first % 10, first /= 10;
  while (first);
  while (top) putchar(fout[--top] + '0');
}
const int maxN = 1e5 + 5, SIZE = 800, oo = 0x3f3f3f3f;
struct node {
  int r, c;
  node() {}
  node(int _r, int _c) : r(_r), c(_c) {}
  bool operator<(const node& rhs) const {
    return c < rhs.c || (c == rhs.c && r < rhs.r);
  }
};
node S[maxN];
int N, K;
void input() {
  read(N), read(K);
  for (int i = 1; i <= K; ++i) {
    read(S[i].r), read(S[i].c);
  }
}
bool flag[maxN][SIZE + 5];
int f[SIZE + 5], cnt[SIZE + 5];
void exec() {
  int ans = 0;
  for (int i = 1; i <= K; ++i) {
    int first = S[i].r, second = S[i].c;
    if (N - first + 1 < SIZE)
      flag[second][N - first + 1] = true;
    else
      ans += 3;
  }
  for (int i = 1; i <= SIZE + 1; ++i) f[i] = oo;
  for (int i = 1; i <= N; ++i) {
    cnt[1 + SIZE] = 0;
    int mc = oo;
    for (int j = SIZE; ~j; --j) cnt[j] = cnt[j + 1] + flag[i][j];
    for (int j = 0; j <= SIZE; ++j) {
      umin(mc, f[j]);
      f[j] = std::min(f[j + 1], mc + (j ? j * (j + 1) / 2 + 2 : 0)) +
             cnt[j + 1] * 3;
    }
  }
  write(*std::min_element(f, f + SIZE + 1) + ans), putchar('\n');
}
int main() {
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  input();
  exec();
  return 0;
}
