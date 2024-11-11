#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
A convert(B x) {
  stringstream ss;
  ss << x;
  A ret;
  ss >> ret;
  return ret;
}
const int oo = ~0u >> 2;
const double eps = 1e-10, pi = acos(-1);
const int mn = 51, mo = 1000000007;
const int fx[8][2] = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                      {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
struct po {
  int x, y;
};
struct circle {
  po o;
  int r;
};
vector<circle> a;
vector<pair<double, bool> > Q;
int n, k;
long long Ans;
void ins(double l, double r) {
  while (l > eps && r - pi * 2 > -eps) l -= pi * 2, r -= pi * 2;
  while (pi * 2 - l > eps) {
    Q.push_back(pair<double, bool>(l + eps, 1));
    Q.push_back(pair<double, bool>(r - eps, 0));
    l += pi * 2, r += pi * 2;
  }
}
int main() {
  a.clear();
  scanf("%d%d", &n, &k);
  for (int i = 0; i <= n - 1; ++i) {
    circle T;
    scanf("%d%d%d", &T.o.x, &T.o.y, &T.r);
    a.push_back(T);
  }
  Ans = 0;
  for (int i = 0; i <= n - 1; ++i) {
    Q.clear();
    for (int j = 0; j <= n - 1; ++j)
      if (i != j) {
        double Ang = atan2(a[j].o.x - a[i].o.x, a[j].o.y - a[i].o.y);
        double l =
            sqrt(((double)(a[j].o.x - a[i].o.x) * (a[j].o.x - a[i].o.x)) +
                 ((double)(a[j].o.y - a[i].o.y) * (a[j].o.y - a[i].o.y)));
        double alpha = pi / 2 - asin((a[i].r - a[j].r) / l);
        double beita = pi / 2 - asin((a[i].r + a[j].r) / l);
        ins(Ang - alpha, Ang - beita);
        ins(Ang + beita, Ang + alpha);
      }
    sort(Q.begin(), Q.end());
    int Now = 0;
    for (int j = 0; j <= (int)Q.size() - 1; ++j)
      if (!Q[j].second)
        --Now;
      else
        Ans = max(Ans, (long long)++Now);
  }
  Ans = (long long)Ans * k + (long long)k * (k + 1) / 2 + n;
  cout << Ans << endl;
}
