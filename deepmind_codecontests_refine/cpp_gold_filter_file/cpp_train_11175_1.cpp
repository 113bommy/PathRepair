#include <bits/stdc++.h>
using namespace std;
template <class T>
T By(T x, T y, T P) {
  T F1 = 0;
  while (y) {
    if (y & 1) {
      F1 += x;
      if (F1 < 0 || F1 >= P) F1 -= P;
    }
    x <<= 1;
    if (x < 0 || x >= P) x -= P;
    y >>= 1;
  }
  return F1;
}
template <class T>
T Mul(T x, T y, T P) {
  T F1 = 1;
  x %= P;
  while (y) {
    if (y & 1) {
      F1 = By(F1, x, P);
    }
    x = By(x, x, P);
    y >>= 1;
  }
  return F1;
}
template <class T>
T Gcd(T x, T y) {
  if (y == 0) return x;
  T z;
  while (z = x % y) {
    x = y, y = z;
  }
  return y;
}
struct EDGE {
  int T;
  EDGE *Nxt;
};
template <class T>
void UpdataMin(T &x, T y) {
  if (y < x) {
    x = y;
  }
}
template <class T>
void UpdataMax(T &x, T y) {
  if (x < y) {
    x = y;
  }
}
pair<int, int> Found[1501][1501];
pair<int, int> Bfs[2250001];
pair<int, int> Npos, Nlabel, Pos, Label;
const pair<int, int> D[4] = {make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0),
                             make_pair(0, -1)};
char Map[1501][1501];
int N, M;
int H, T;
int main() {
  memset(Found, 127, sizeof(Found));
  scanf("%d%d", &N, &M);
  H = -1, T = 0;
  for (int i = 0; i < (N); ++i) {
    scanf("%s", Map[i]);
    for (int j = 0; j < (M); ++j)
      if (Map[i][j] == 'S')
        Bfs[0] = make_pair(i, j), Found[i][j] = make_pair(0, 0);
  }
  while (H++ != T) {
    Pos = Bfs[H], Label = Found[Pos.first][Pos.second];
    for (int i = 0; i < (4); ++i) {
      Npos = Pos, Nlabel = Label;
      Npos.first += D[i].first, Npos.second += D[i].second;
      if (Npos.first == -1) Nlabel.first--, Npos.first = N - 1;
      if (Npos.second == -1) Nlabel.second--, Npos.second = M - 1;
      if (Npos.first == N) Nlabel.first++, Npos.first = 0;
      if (Npos.second == M) Nlabel.second++, Npos.second = 0;
      if (Map[Npos.first][Npos.second] != '#') {
        if (Found[Npos.first][Npos.second].first == 0x7f7f7f7f) {
          Found[Npos.first][Npos.second] = Nlabel;
          Bfs[++T] = Npos;
        } else {
          if (Found[Npos.first][Npos.second].first != Nlabel.first ||
              Found[Npos.first][Npos.second].second != Nlabel.second) {
            puts("Yes");
            scanf("%d", &N);
            return 0;
          }
        }
      }
    }
  }
  puts("No");
  scanf("%d", &N);
  return 0;
}
