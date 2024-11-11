#include <bits/stdc++.h>
using namespace std;
int k, n;
double X[4010], Y[4010];
double eps = 1e4, mx = 2e6;
double sqr(double x) { return x * x; }
double dis(int a, int b, int c, int d) { return sqrt(sqr(c - a) + sqr(d - b)); }
double avg1[10010], avg2[10010];
double getval(double x, double y) {
  vector<double> V(0);
  for (int s = 1; s <= k * n; s++) V.push_back(pow(dis(x, y, X[s], Y[s]), 2));
  sort(V.begin(), V.end());
  for (int i = 0; i < V.size(); i++) avg1[i] = V[i], avg2[i] = V[i] * V[i];
  for (int i = 1; i < V.size(); i++)
    avg1[i] += avg1[i - 1], avg2[i] += avg2[i - 1];
  double magic = 1e100;
  int n = ::n - 2;
  for (int i = n; i < V.size(); i++)
    magic = min(magic, avg2[i] - avg2[i - n] - sqr(avg1[i] - avg1[i - n]) / n);
  return magic;
}
double getr(double x, double y) {
  vector<double> V(0);
  for (int s = 1; s <= k * n; s++) V.push_back(dis(x, y, X[s], Y[s]));
  sort(V.begin(), V.end());
  for (int i = 0; i < V.size(); i++) avg1[i] = V[i], avg2[i] = V[i] * V[i];
  for (int i = 1; i < V.size(); i++)
    avg1[i] += avg1[i - 1], avg2[i] += avg2[i - 1];
  double magic = 1e100;
  int v;
  int n = ::n - 2;
  for (int i = n; i < V.size(); i++) {
    double s = avg2[i] - avg2[i - n] - sqr(avg1[i] - avg1[i - n]) / n;
    if (s < magic) magic = s, v = i;
  }
  return (avg1[v] - avg1[v - n]) / n;
}
double Ansx[200000], Ansy[1200000], qwq[200000];
int tmp[200000];
int cnt = 0;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
double rd() { return (double)rng() / pow(2, 63) - 1; }
bool cmp(int x, int y) { return qwq[x] < qwq[y]; }
int main() {
  scanf("%d%d", &k, &n);
  for (int i = 1; i <= k * n; i++) {
    scanf("%lf%lf", &X[i], &Y[i]);
  }
  for (int i = -100; i <= 100; i++)
    for (int j = -100; j <= 100; j++)
      if (dis(0, 0, i * 10000, j * 10000) <= 1e6)
        Ansx[++cnt] = i * 10000, Ansy[cnt] = j * 10000,
        qwq[cnt] = getval(i * 10000, j * 10000);
  for (int i = 1; i <= k; i++) {
    for (int i = 1; i <= cnt; i++) tmp[i] = i;
    sort(tmp + 1, tmp + cnt + 1, cmp);
    printf("%.12lf %.12lf %.12lf\n", Ansx[tmp[1]], Ansy[tmp[1]],
           getr(Ansx[tmp[1]], Ansy[tmp[1]]));
    double x = Ansx[tmp[1]], y = Ansy[tmp[1]];
    for (int i = 1; i <= cnt; i++)
      if (dis(Ansx[i], Ansy[i], x, y) <= 4e5) qwq[i] = 1e100;
  }
  return 0;
}
