#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const long long Inf = 1e10;
const int P = 1e9 + 7;
const int N = 100005;
inline long long IN() {
  long long x = 0;
  int ch = 0, f = 0;
  for (ch = getchar(); ch != -1 && (ch < 48 || ch > 57); ch = getchar())
    f = (ch == '-');
  for (; ch >= 48 && ch <= 57; ch = getchar())
    x = (x << 1) + (x << 3) + ch - '0';
  return f ? (-x) : x;
}
template <typename T>
inline int chkmin(T &a, const T &b) {
  if (b < a) return a = b, 1;
  return 0;
}
template <typename T>
inline int chkmax(T &a, const T &b) {
  if (b > a) return a = b, 1;
  return 0;
}
void renew(int &x, const int &y) {
  x += y;
  if (x >= P) x -= P;
  if (x < 0) x += P;
}
int Pow(int x, int y, int p) {
  int a = 1;
  for (; y; y >>= 1, x = (long long)x * x % p)
    if (y & 1) a = (long long)a * x % p;
  return a;
}
long long T;
vector<pair<pair<int, int>, pair<int, int> > > blk;
int d[55];
void add(int x1, int y1, int x2, int y2) {
  blk.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
}
void print() {
  printf("41 41\n");
  printf("%d\n", (int)blk.size());
  for (auto v : blk)
    printf("%d %d %d %d\n", v.first.first, v.first.second, v.second.first,
           v.second.second);
}
int main() {
  cin >> T;
  for (int i = (int)(0); i <= (int)(37); i++) {
    d[i] = T % 3;
    T /= 3;
  }
  for (int i = (int)(4); i <= (int)(40); i++) add(i - 3, i, i - 2, i);
  for (int i = (int)(4); i <= (int)(40); i++) add(i, i - 3, i, i - 2);
  for (int i = (int)(6); i <= (int)(60); i++) add(i, i - 5, i, i - 4);
  for (int i = (int)(6); i <= (int)(60); i++) add(i - 5, i, i - 4, i);
  for (int i = (int)(6); i <= (int)(60); i++) add(i - 1, i - 5, i, i - 5);
  for (int i = (int)(6); i <= (int)(60); i++) add(i - 5, i - 1, i - 5, i);
  add(39, 40, 39, 41);
  add(40, 40, 40, 41);
  add(40, 39, 41, 39);
  add(40, 40, 41, 40);
  for (int i = (int)(0); i <= (int)(37); i++) {
    if (d[i] <= 0) {
      add(i + 1, i + 3, i + 1, i + 4);
    }
    if (d[i] <= 1) {
      add(i + 3, i + 1, i + 4, i + 1);
    }
  }
  print();
  return 0;
}
