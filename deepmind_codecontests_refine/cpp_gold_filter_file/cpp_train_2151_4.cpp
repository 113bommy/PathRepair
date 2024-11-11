#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f;
const long long MOD = 1000000007;
const int IT_MAX = 1 << 17;
const int MX = 1000005;
long double myrand() {
  long double t = 1.0 * rand();
  return (t + 1.0 * rand() / RAND_MAX) / RAND_MAX;
}
int r[30050];
int root(int x) { return (x == r[x]) ? x : (r[x] = root(r[x])); }
map<pair<int, int>, int> Mx;
int ch(pair<int, int> x) {
  if (Mx.count(x)) return Mx[x];
  int t = (int)Mx.size() + 1;
  return Mx[x] = t;
}
int D;
long double u[5][5];
long double u2[5];
long double u3[5];
vector<vector<long double>> readInput() {
  int N, i, j, k;
  scanf("%d", &N);
  double t;
  int cc = 0;
  vector<vector<long double>> Vr;
  for (i = 0; i < N; i++) {
    for (j = 0; j < D; j++) scanf("%lf", &t), u2[j] = u3[j] = t;
    for (j = 0; j < cc; j++) {
      long double s = 0;
      for (k = 0; k < D; k++) s += u[j][k] * u3[k];
      for (k = 0; k < D; k++) u2[k] -= s * u[j][k];
    }
    for (j = 0; j < D; j++)
      if (abs(u2[j]) > 1e-7) break;
    if (j >= D) continue;
    long double s = 0;
    for (j = 0; j < D; j++) s += u2[j] * u2[j];
    for (j = 0; j < D; j++) u[cc][j] = u2[j] / sqrt(s);
    vector<long double> Vu;
    for (j = 0; j < D; j++) Vu.push_back(u[cc][j]);
    Vr.push_back(Vu);
    cc++;
  }
  return Vr;
}
vector<vector<long double>> in[30050];
vector<long double> val[30050];
long double A[5][5];
long double B[5];
void mycalc() {
  int i, j, k;
  for (i = 0; i < D; i++) {
    int mxp = i;
    for (j = i + 1; j < D; j++)
      if (abs(A[mxp][i]) < abs(A[j][i])) mxp = j;
    for (j = i; j < D; j++) swap(A[i][j], A[mxp][j]);
    swap(B[i], B[mxp]);
    assert(abs(A[i][i]) > 1e-9);
    for (j = i + 1; j < D; j++) {
      long double t = A[j][i] / A[i][i];
      for (k = i; k < D; k++) A[j][k] -= t * A[i][k];
      B[j] -= t * B[i];
    }
  }
  for (i = D - 1; i >= 0; i--) {
    for (j = i + 1; j < D; j++) B[i] -= B[j] * A[i][j];
    B[i] /= A[i][i];
  }
}
int mycmp(vector<long double> &A, vector<long double> &B) {
  for (int i = 0; i < A.size(); i++) {
    if (abs(A[i] - B[i]) >
        1e-12 * max((long double)1.0, max(abs(A[i]), abs(B[i])))) {
      if (A[i] < B[i])
        return -1;
      else
        return 1;
    }
  }
  return 0;
}
int ans[30050];
int tans[30050];
int main() {
  srand(1245);
  int N, i, j, k;
  scanf("%d %d", &N, &D);
  for (i = 1; i <= N; i++) {
    in[i] = readInput();
  }
  while (clock() < 1.0 * CLOCKS_PER_SEC) {
    for (i = 1; i <= N; i++) r[i] = i;
    for (i = 1; i <= N; i++) val[i].clear();
    for (i = 0; i <= D; i++) {
      vector<int> Vl;
      for (j = 1; j <= N; j++)
        if (in[j].size() == i) Vl.push_back(j);
      if (Vl.empty()) continue;
      if (i == 0 || i == D) {
        for (auto it : Vl) r[root(it)] = root(Vl[0]);
        continue;
      }
      vector<vector<long double>> Vq;
      for (j = 0; j <= D - i; j++) {
        vector<long double> Vu;
        for (k = 0; k < D; k++) Vu.push_back(myrand());
        Vq.push_back(Vu);
      }
      for (auto it : Vl) {
        for (j = 0; j < i; j++)
          for (k = 0; k < D; k++) A[k][j] = in[it][j][k];
        for (j = 0; j < D - i; j++)
          for (k = 0; k < D; k++) A[k][j + i] = Vq[j][k];
        for (j = 0; j < D; j++) B[j] = Vq[D - i][j];
        mycalc();
        for (j = i; j < D; j++) val[it].push_back(B[j]);
      }
      vector<long double> Vx;
      for (j = 0; j < D - i; j++) Vx.push_back(myrand());
      sort((Vl).begin(), (Vl).end(), [&](int a, int b) {
        long double v1 = 0;
        long double v2 = 0;
        for (j = 0; j < D - i; j++) {
          v1 += Vx[j] * val[a][j];
          v2 += Vx[j] * val[b][j];
        }
        return v1 < v2;
      });
      for (j = 0; j + 1 < Vl.size(); j++)
        if (mycmp(val[Vl[j]], val[Vl[j + 1]]) == 0)
          r[root(Vl[j])] = root(Vl[j + 1]);
    }
    Mx.clear();
    for (i = 1; i <= N; i++) tans[i] = ch(pair<int, int>(ans[i], root(i)));
    for (i = 1; i <= N; i++) ans[i] = tans[i];
  }
  for (i = 1; i <= N; i++) printf("%d ", ans[i]);
  return !printf("\n");
}
