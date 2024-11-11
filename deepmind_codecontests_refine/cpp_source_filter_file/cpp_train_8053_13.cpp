#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
};
struct pointt {
  double x, y;
  int ind;
};
double aa, bb, cc, dd, aaa, ccc, xx, yy;
vector<point> P;
vector<pointt> Q;
int n, res, ans, i;
char ch;
double tana, K, newx, newy;
int num[1000000], prevv[1000000], s[1000000];
bool cmp(point a, point b) { return (a.y > b.y || (a.y == b.y && a.x > b.x)); }
int prev(int x) { return x & (x - 1); }
int next(int x) { return 2 * x - prev(x); }
int maxx(int l) {
  int h = 0;
  while (l > 0) {
    h = (h > s[l] ? h : s[l]);
    l = prev(l);
  }
  return h;
}
void update(int pos, int delta) {
  while (pos <= 100000) {
    s[pos] = (s[pos] > delta ? s[pos] : delta);
    pos = next(pos);
  }
}
bool cmp2(pointt a, pointt b) {
  double X1 = a.x - (double)a.y / tana;
  double X2 = b.x - (double)b.y / tana;
  return X1 > X2;
}
double count(pointt a) {
  double X1 = a.x - (double)a.y / tana;
  return X1;
}
int main() {
  scanf("%d", &n);
  scanf("%lf", &aa);
  scanf("%c", &ch);
  scanf("%lf", &bb);
  scanf("%lf", &cc);
  scanf("%c", &ch);
  scanf("%lf", &dd);
  if (bb == 0) bb += 0.0000000000001;
  if (dd == 0) dd += 0.0000000000001;
  aa += 0.00000001;
  cc -= 0.00000001;
  while (n--) {
    scanf("%lf %lf", &xx, &yy);
    if (yy * bb - xx * aa >= 0 && xx * cc - yy * dd >= 0)
      P.push_back((point){xx, yy});
  }
  for (i = 0; i < P.size(); i++) {
    swap(aa, bb);
    xx = P[i].x;
    yy = P[i].y;
    K = (double)(yy * aa - xx * bb) / (xx * aa + yy * bb);
    K = (double)K * K;
    newx = sqrt((double)(xx * xx + yy * yy) / (K + 1));
    newy = sqrt(xx * xx + yy * yy - newx * newx);
    P[i] = (point){newx, newy};
    swap(aa, bb);
  }
  tana = (double)((double)cc / dd - (double)aa / bb) /
         (1.0 + (double)aa * cc / (bb * dd));
  sort(P.begin(), P.end(), cmp);
  for (i = 0; i < P.size(); i++) Q.push_back((pointt){P[i].x, P[i].y, i});
  sort(Q.begin(), Q.end(), cmp2);
  for (i = 0; i < Q.size(); i++) num[Q[i].ind] = i;
  for (i = 0; i < P.size(); i++) {
    ans = maxx(num[i]) + 1;
    update(num[i] + 1, ans);
    res = (res > ans ? res : ans);
  }
  cout << res << endl;
}
