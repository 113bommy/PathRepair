#include <bits/stdc++.h>
using namespace std;
const int NMax = 1000100 * 2, MMax = 101000;
int N;
int xmin, xmax, ymin, ymax;
pair<long double, long double> line[MMax];
pair<int, int> area[MMax], P1[MMax];
vector<long double> X[NMax], Y[NMax];
long double sum[NMax];
long double Ceil(long double a) { return ceil(a); }
long double Floor(long double a) { return floor(a); }
pair<long double, long double> P[MMax];
bool flag[NMax];
int main() {
  scanf("%d", &N);
  xmin = 100000000;
  xmax = -100000000;
  ymin = 100000000;
  ymax = -100000000;
  int minx = 100000000, miny = 100000000;
  for (int i = 1; i <= N; i++) {
    int first, second;
    scanf("%d%d", &first, &second);
    minx = min(minx, first);
    miny = min(miny, second);
    P1[i].first = first;
    P1[i].second = second;
    P[i].first = (long double)first;
    P[i].second = (long double)second;
  }
  for (int i = 1; i <= N; i++)
    P[i].first -= (long double)minx, P[i].second -= (long double)miny,
        P1[i].first -= minx, P1[i].second -= miny;
  for (int i = 1; i <= N; i++) {
    xmin = min(xmin, P1[i].first);
    ymin = min(ymin, P1[i].second);
    xmax = max(xmax, P1[i].first);
    ymax = max(ymax, P1[i].second);
  }
  if (P1[N].first == P1[1].first) flag[0] = 1;
  for (int i = 1; i <= N; i++) {
    int j = i + 1;
    if (j > N) j = 1;
    if (P1[i].first == P1[j].first) {
      line[i].first = -1;
      line[i].second = -1;
      flag[i] = 1;
      area[i].first = P1[i].first;
      area[i].second = P1[j].first;
      if (!flag[i - 1]) {
        X[area[i].first].push_back(P[i].second);
      }
      if (P1[j].first != P1[(j % N) + 1].first)
        X[area[i].first].push_back(P[j].second);
    } else {
      line[i].first = (P[j].second - P[i].second) / (P[j].first - P[i].first);
      line[i].second = P[j].second - P[j].first * line[i].first;
      area[i].first = P1[i].first;
      area[i].second = P1[j].first;
      if (area[i].first < area[i].second)
        for (int j = flag[i - 1] ? (area[i].first + 1) : area[i].first;
             j < area[i].second; j++)
          X[j].push_back(line[i].first * (long double)j + line[i].second);
      else
        for (int j = flag[i - 1] ? (area[i].first - 1) : area[i].first;
             j > area[i].second; j--)
          X[j].push_back(line[i].first * (long double)j + line[i].second);
    }
  }
  memset(flag, 0, sizeof(flag));
  if (P1[N].second == P1[1].second) flag[0] = 1;
  for (int i = 1; i <= N; i++) {
    swap(P[i].first, P[i].second);
    swap(P1[i].first, P1[i].second);
    int j = i + 1;
    if (j > N) j = 1;
    swap(P[j].first, P[j].second);
    swap(P1[j].first, P1[j].second);
    if (P1[i].first == P1[j].first) {
      line[i].first = -1;
      line[i].second = -1;
      flag[i] = 1;
      area[i].first = P1[i].first;
      area[i].second = P1[j].first;
      if (!flag[i - 1]) Y[area[i].first].push_back(P[i].second);
      if (P1[j].first != P1[(j % N) + 1].second)
        Y[area[i].first].push_back(P[j].second);
    } else {
      line[i].first = (P[j].second - P[i].second) / (P[j].first - P[i].first);
      line[i].second = P[j].second - P[j].first * line[i].first;
      area[i].first = P1[i].first;
      area[i].second = P1[j].first;
      if (area[i].first < area[i].second)
        for (int j = flag[i - 1] ? (area[i].first + 1) : area[i].first;
             j < area[i].second; j++)
          Y[j].push_back(line[i].first * (long double)j + line[i].second);
      else
        for (int j = flag[i - 1] ? (area[i].first - 1) : area[i].first;
             j > area[i].second; j--)
          Y[j].push_back(line[i].first * (long double)j + line[i].second);
    }
    swap(P[i].first, P[i].second);
    swap(P[j].first, P[j].second);
    swap(P1[i].first, P1[i].second);
    swap(P1[j].first, P1[j].second);
  }
  for (int i = xmin; i <= xmax; i++) {
    for (int j = 0; j < X[i].size(); j++)
      if (X[i][j] <= 0 && -X[i][j] < 1e-8f || (X[i][j] >= 0 && X[i][j] < 1e-8f))
        X[i][j] = +0.0;
    sort(X[i].begin(), X[i].end());
    vector<long double>::iterator it = unique(X[i].begin(), X[i].end());
    X[i].resize(distance(X[i].begin(), it));
    if (X[i].size() == 1) X[i].push_back(X[i][0]);
    if (X[i][0] > X[i][1]) swap(X[i][0], X[i][1]);
    X[i][0] = (long double)Ceil(X[i][0]);
    X[i][1] = (long double)Floor(X[i][1]);
  }
  for (int i = ymin; i <= ymax; i++) {
    for (int j = 0; j < Y[i].size(); j++)
      if (Y[i][j] <= 0 && -Y[i][j] < 1e-8f || (Y[i][j] >= 0 && Y[i][j] < 1e-8f))
        Y[i][j] = +0.0;
    sort(Y[i].begin(), Y[i].end());
    vector<long double>::iterator it = unique(Y[i].begin(), Y[i].end());
    Y[i].resize(distance(Y[i].begin(), it));
    if (Y[i].size() == 1) Y[i].push_back(Y[i][0]);
    if (Y[i][0] > Y[i][1]) swap(Y[i][0], Y[i][1]);
    Y[i][0] = (long double)Ceil(Y[i][0]);
    Y[i][1] = (long double)Floor(Y[i][1]);
  }
  long double ret = 0, div = 0, cnt = 0, mul = 0, mul1 = 0;
  for (int i = xmin; i <= xmax; i++)
    mul += X[i][1] - X[i][0] + 1,
        mul1 += (long double)i * (X[i][1] - X[i][0] + 1);
  for (int i = xmin; i <= xmax; i++) {
    div = div + X[i][1] - X[i][0] + 1;
    long double tmp = mul - (X[i][1] - X[i][0] + 1),
                tmp1 = mul1 - (long double)i * (X[i][1] - X[i][0] + 1.0);
    ret =
        ret + (X[i][1] - X[i][0] + 1.0) * (long double)i * (long double)i * tmp;
    ret = ret - (X[i][1] - X[i][0] + 1.0) * (long double)i * tmp1;
  }
  cnt = 0;
  mul = 0;
  mul1 = 0;
  for (int i = ymin; i <= ymax; i++)
    mul += Y[i][1] - Y[i][0] + 1.0,
        mul1 += (long double)i * (Y[i][1] - Y[i][0] + 1.0);
  for (int i = ymin; i <= ymax; i++) {
    long double tmp = mul - (Y[i][1] - Y[i][0] + 1.0),
                tmp1 = mul1 - (long double)i * (Y[i][1] - Y[i][0] + 1.0);
    ret =
        ret + (Y[i][1] - Y[i][0] + 1.0) * (long double)i * (long double)i * tmp;
    ret = ret - (Y[i][1] - Y[i][0] + 1.0) * (long double)i * tmp1;
  }
  div = div * (div - 1.0);
  ret = ret / div;
  printf("%.10lf\n", (double)ret);
  getchar();
  getchar();
  return 0;
}
