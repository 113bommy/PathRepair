#include <bits/stdc++.h>
using namespace std;
template <class T>
T inline sqr(T x) {
  return x * x;
}
template <class T>
inline T myAbs(T a) {
  return a > 0 ? a : -a;
}
struct lol {
  int m, v, n;
  double h;
};
vector<lol> a;
bool compr(lol a, lol b) {
  if (a.m == b.m) return a.v < b.v;
  return a.m > b.m;
}
int main() {
  int n, k, h;
  vector<int> res, our;
  cin >> n >> k >> h;
  a.resize(n);
  res.resize(k);
  our.resize(k);
  for (int i = 0; i < (int)(n); ++i) {
    scanf("%d", &a[i].m);
  }
  for (int i = 0; i < (int)(n); ++i) {
    scanf("%d", &a[i].v);
    a[i].n = i + 1;
  }
  double l = 0;
  double r = 2000000000.0;
  bool yes = false;
  sort(a.begin(), a.end(), compr);
  for (int test = 0; test < (int)(500); ++test) {
    double t = (l + r) / 2;
    for (int i = 0; i < (int)(n); ++i) {
      a[i].h = 1.0 * t * a[i].v;
    }
    int j = k;
    res.clear();
    res.resize(k);
    for (int i = 0; i < (int)(n); ++i) {
      if (j == 0) break;
      if (a[i].h >= j * h) res[j - 1] = a[i].n, --j;
    }
    if (j > 0) {
      l = t;
    } else {
      r = t;
      our = res;
    }
  }
  for (int i = 0; i < (int)(k - 1); ++i) {
    cout << our[i] << " ";
  }
  cout << our[k - 1] << endl;
  return 0;
}
