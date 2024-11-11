#include <bits/stdc++.h>
using namespace std;
template <class T>
bool isPrime(T x) {
  if (x <= 1) return false;
  T i;
  for (i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
template <class T>
class Prime {
 public:
  vector<T> z;
  Prime() {
    z.resize(1e5 + 7);
    for (int i = (0); i < (((int)z.size())); i++) z[i] = 1;
    z[0] = 0;
    z[1] = 0;
    T j;
    for (int i = (2); i < (((int)z.size())); i++) {
      if (z[i]) {
        j = i + i;
        while (j < ((int)z.size())) {
          z[j] = 0;
          j += i;
        }
      }
    }
  }
};
template <class T>
double dist(T x1, T y1, T x2, T y2) {
  return sqrt(1. * (x2 - x1) * (x2 - x1) + 1. * (y2 - y1) * (y2 - y1));
}
template <class T>
class Point {
 public:
  T x, y;
  Point() {}
  Point(T a, T b) : x(a), y(b) {}
  bool operator==(const Point& tmp) const { return (x == tmp.x && y == tmp.y); }
  Point operator-(const Point& tmp) const {
    return Point<T>(x - tmp.x, y - tmp.y);
  }
};
char toLowerCase(char x) { return (x + 32); }
char toUpperCase(char x) { return (x - 32); }
bool isUpperCase(char x) { return (65 <= x && x <= 90) ? 1 : 0; }
bool isLowerCase(char x) { return (97 <= x && x <= 122) ? 1 : 0; }
bool isAlpha(char x) { return (isUpperCase(x) || isLowerCase(x)) ? 1 : 0; }
bool isDigit(char x) { return ('0' <= x && x <= '9') ? 1 : 0; }
template <class T>
T toDec(string s) {
  stringstream is(s);
  T res;
  is >> res;
  return res;
}
template <class T>
string toStr(T n) {
  string s;
  stringstream is;
  is << n;
  is >> s;
  return s;
}
template <class T>
void checkmin(T& a, T b) {
  if (a > b) a = b;
}
template <class T>
void checkmax(T& a, T b) {
  if (a < b) a = b;
}
const int MAXN = 100;
vector<vector<int> > graph(100, vector<int>(MAXN, 0));
vector<int> labelX, labelY, usedX, usedY, linkTo;
int id(char c) { return (c <= 'Z' ? 26 + c - 'A' : c - 'a'); }
char itoa(int c) { return (c < 26 ? 'a' + c : 'A' + c - 26); }
bool findPath(int i, int n) {
  usedX[i] = 1;
  for (int j = 0; j < n; j++) {
    if (!usedY[j] && labelX[i] + labelY[j] == graph[i][j] && linkTo[j] != -1) {
      usedY[j] = true;
      linkTo[j] = i;
      return true;
    }
  }
  for (int j = 0; j < n; j++) {
    if (!usedY[j] && labelX[i] + labelY[j] == graph[i][j]) {
      usedY[j] = true;
      if (linkTo[j] == -1 || findPath(linkTo[j], n)) {
        linkTo[j] = i;
        return true;
      }
    }
  }
  return false;
}
int kuhnMunkres(int K) {
  labelX = vector<int>(MAXN, 0);
  labelY = vector<int>(MAXN, 0);
  usedX = vector<int>(MAXN, 0);
  usedY = vector<int>(MAXN, 0);
  linkTo = vector<int>(MAXN, -1);
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < K; j++) {
      labelX[i] = max(labelX[i], graph[i][j]);
    }
  }
  for (int k = 0; k < K; k++) {
    while (true) {
      usedX = vector<int>(MAXN, 0);
      usedY = vector<int>(MAXN, 0);
      if (findPath(k, K)) break;
      int delta = 1e9;
      for (int i = 0; i < K; i++) {
        if (usedX[i]) {
          for (int j = 0; j < K; j++) {
            if (!usedY[j]) {
              delta = min(delta, labelX[i] + labelY[j] - graph[i][j]);
            }
          }
        }
      }
      if (delta == 0 || delta == 1e9) break;
      for (int i = 0; i < K; i++) {
        if (usedX[i]) labelX[i] -= delta;
        if (usedY[i]) labelY[i] += delta;
      }
    }
  }
  int max_weight = 0;
  for (int i = 0; i < K; i++) {
    max_weight += labelX[i] + labelY[i];
  }
  return max_weight;
}
int main() {
  int n, k;
  string a, b;
  cin >> n >> k >> a >> b;
  for (int i = 0; i < n; i++) graph[id(a[i])][id(b[i])]++;
  cout << kuhnMunkres(k) << "\n";
  vector<int> ans(MAXN, 0);
  for (int i = 0; i < k; i++) {
    ans[linkTo[i]] = i;
  }
  for (int i = 0; i < k; i++) {
    cout << itoa(ans[i]);
  }
  return 0;
}
