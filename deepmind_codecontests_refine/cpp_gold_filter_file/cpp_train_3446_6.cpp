#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(const T& t) {
  return t * t;
}
template <class T>
T abs(const T& t) {
  return ((t > 0) ? (t) : (-t));
}
void initialize() {
  freopen("_.in", "r", stdin);
  freopen("_.out", "w", stdout);
}
struct Point {
  int x;
  int y;
  Point(int x_, int y_) : x(x_), y(y_) {}
};
const int W = 2000;
const int MAXS = 300;
const int MAX = 3 * (int)1e5 + 10;
int w[MAX];
vector<long long> precalc[(MAX / W) + 1][MAXS];
int n;
void calc() {
  for (int i = 0; i <= n / W; ++i) {
    int start = i * W;
    for (int b = 1; b < MAXS; ++b) {
      precalc[i][b].resize(b);
      for (int s = 0; s < b; ++s) {
        long long res = 0;
        for (int k = start + s; k < start + W && k < n; k += b) {
          res += w[k];
        }
        precalc[i][b][s] = res;
      }
    }
  }
}
int main() {
  cerr << "Reading...\n";
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &w[i]);
  }
  cerr << "Precalcing...\n";
  calc();
  cerr << "Working...\n";
  int q;
  cin >> q;
  cerr << "q = " << q << endl;
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    a -= 1;
    long long res = 0;
    if (b >= MAXS) {
      for (int i = a; i < n; i += b) {
        res += w[i];
      }
    } else {
      long long ind = a / W;
      for (int j = a; j < (ind + 1) * W && j < n; j += b) {
        res += w[j];
      }
      for (int i = ind + 1; i <= n / W; ++i) {
        int start = i * W;
        int pos = a + ((start - a) / b) * b;
        while (pos < start) {
          pos += b;
        }
        res += precalc[i][b][pos - start];
      }
    }
    cout << res << "\n";
  }
  return 0;
}
