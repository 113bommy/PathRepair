#include <bits/stdc++.h>
using namespace std;
const int RNG = 1000003;
const int RNGT = RNG * 4;
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 87;
const double pi = 2 * acos(0.0);
inline int _Int() {
  int x;
  scanf("%d", &x);
  return x;
}
inline long long _LLi() {
  long long x;
  scanf("%lld", &x);
  return x;
}
void pruts() {
  puts("-1");
  exit(EXIT_SUCCESS);
}
int dirX[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dirY[] = {0, 1, 0, -1, 1, -1, -1, 1};
int rX[] = {1, 1, 2, 2, -1, -1, -2, -2};
int rY[] = {2, -2, 1, -1, 2, -2, 1, -1};
template <class T>
T tri_Area(T x1, T y1, T x2, T y2, T x3, T y3) {
  return abs(x1 * (y2 - y3) - y1 * (x2 - x3) + (x2 * y3 - x3 * y2));
};
template <class T>
T Distance(T x1, T y1, T x2, T y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
};
template <class T>
T bigMod(T n, T p, T m) {
  if (p == 0) return 1;
  if (p & 1) return (n * bigMod(n, p - 1, m)) % m;
  T x = bigMod(n, p / 2, m);
  return (x * x) % m;
};
int Case;
int sset(int N, int pos) { return N = N | (1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
int A[RNG], n, m, flag;
string str[600];
void Hunger() {
  n = _Int();
  m = _Int();
  for (int i = 0; i < n; i++) cin >> str[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (str[i][j] == 'W') {
        int x = i + 1;
        if (x < n && x >= 0) {
          if (str[x][j] == '.') str[x][j] = 'D';
          if (str[x][j] == 'S') {
            cout << "No" << endl;
            return;
          }
        }
        x = i - 1;
        if (x < n && x >= 0) {
          if (str[x][j] == '.') str[x][j] = 'D';
          if (str[x][j] == 'S') {
            cout << "No" << endl;
            return;
          }
        }
        x = j + 1;
        if (x < m && x >= 0) {
          if (str[i][x] == '.') str[i][x] = 'D';
          if (str[i][x] == 'S') {
            cout << "No" << endl;
            return;
          }
        }
        x = j - 1;
        if (x < m && x >= 0) {
          if (str[i][x] == '.') str[i][x] = 'D';
          if (str[i][x] == 'S') {
            cout << "No" << endl;
            return;
          }
        }
      }
    }
  }
  cout << "Yes" << endl;
  for (int i = 0; i < n; i++) cout << str[i] << endl;
}
int main() {
  Hunger();
  return 0;
}
