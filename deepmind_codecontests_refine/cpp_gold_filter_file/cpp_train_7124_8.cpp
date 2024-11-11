#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-7L;
const long double PI = atan(1) * 4.0;
int N, D;
int X[20002], Y[20002], R[20002];
vector<pair<long double, int> > V;
vector<pair<long double, long double> > Rn;
int result;
long double g_dist(long double xn1, long double yn1, long double xn2,
                   long double yn2) {
  return sqrt((xn1 - xn2) * (xn1 - xn2) + (yn1 - yn2) * (yn1 - yn2));
}
void reg(long double& pn) {
  while (pn < 0) pn += 2 * PI;
  while (pn > 2 * PI) pn -= 2 * PI;
}
int main() {
  cin.sync_with_stdio(false);
  cin >> N >> D;
  for (int i = 1; i <= N; ++i) cin >> X[i] >> Y[i] >> R[i];
  for (int i = 1; i <= N; ++i) {
    long double dnow = g_dist(0, 0, X[i], Y[i]);
    long double dn1 = dnow - R[i], dn2 = dnow + R[i];
    int tn1 = int(dn1 / D) - 1, tn2 = int(dn2 / D) + 1;
    for (int j = max(1, tn1); j <= tn2; ++j)
      if (D * j - dn1 > -eps && D * j - dn2 < eps) {
        long double pnow = atan2(Y[i], X[i]),
                    ang = acos((dnow * dnow + 1.0 * D * j * D * j -
                                1.0 * R[i] * R[i]) /
                               (2 * dnow * D * j));
        long double pn1 = pnow - ang, pn2 = pnow + ang;
        pn2 += 2 * eps;
        reg(pn1);
        reg(pn2);
        V.push_back(make_pair(pn1, 1));
        V.push_back(make_pair(pn2, -1));
        Rn.push_back(make_pair(pn1, pn2));
      }
  }
  sort(V.begin(), V.end());
  int pnow = 0;
  for (int i = 0; i < int(Rn.size()); ++i) {
    long double pn1 = Rn[i].first, pn2 = Rn[i].second - 2 * eps;
    if (pn1 - pn2 < eps) {
      if (pn1 - V[0].first < eps && V[0].first - pn2 < eps) ++pnow;
    } else {
      if (V[0].first - pn1 > -eps || V[0].first - pn2 < eps) ++pnow;
    }
  }
  result = pnow;
  int indnow = 0;
  while (indnow < int(V.size()) && fabs(V[indnow].first - V[0].first) < eps)
    ++indnow;
  for (int i = indnow; i < int(V.size()); ++i) {
    pnow += V[i].second;
    result = max(result, pnow);
  }
  cout << result << '\n';
}
