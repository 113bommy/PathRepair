#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
double sqr(double a) { return a * a; }
struct Node {
  vector<int> nbr;
  int used;
  int p1, p2;
  int init, goal;
  Node() {
    p1 = p2 = 0;
    used = 0;
  }
};
struct St {
  int n, m;
  bool operator<(const St& b) const {
    if (n != b.n) {
      return n < b.n;
    } else
      return m < b.m;
  }
};
double leng(pair<int, int> a, pair<int, int> b) {
  double c = sqr(a.first - b.first) + sqr(a.second - b.second);
  return sqrt(c);
}
double getL(vector<pair<int, int> >& a) {
  double ans = 0;
  for (int i = 0; i < 3; ++i) {
    ans += leng(a[i], a[i + 1]);
  }
  return ans;
}
int main() {
  clock_t start = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(15);
  vector<pair<int, int> > arr;
  int n, m;
  cin >> n >> m;
  double ans = 0;
  double s = n * m - 1;
  double g = 0;
  if (s != 0) g = (m - 1) * (n - 1) / s;
  ans = (g + 1) / n;
  cout << ans;
  return 0;
}
