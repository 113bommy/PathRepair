#include <bits/stdc++.h>
using namespace std;
int N, K;
int X[200010] = {0};
int xp = 0;
long long Ans[100010] = {0};
int Y[200010] = {0};
int yp = 0;
pair<int, int> pot[100010];
int id[100010] = {0};
int A1[100010] = {0};
int A2[100010] = {0};
int Hash[100010] = {0};
int ap1 = 0, ap2 = 0;
bool cmp(int a, int b) { return pot[a].second < pot[b].second; }
int main() {
  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    scanf("%d%d", &pot[i].first, &pot[i].second);
    X[++xp] = pot[i].first - K + 1;
    X[++xp] = pot[i].first + 1;
  }
  sort(pot + 1, pot + N + 1);
  sort(X + 1, X + xp + 1);
  xp = 1;
  for (int i = 2; i <= N * 2; i++)
    if (X[i] != X[i - 1]) X[++xp] = X[i];
  int L = 1, R = 0;
  int S = 0;
  for (int i = 1; i <= xp; i++) {
    ap1 = 0;
    for (; R < N && pot[R + 1].first <= X[i] + K - 1; R++) {
      A1[++ap1] = R + 1;
      Hash[R + 1] = 1;
    }
    sort(A1 + 1, A1 + ap1 + 1, cmp);
    for (; L <= N && pot[L].first < X[i]; L++) Hash[L] = 0;
    ap2 = 0;
    for (int first = 1; first <= S; first++)
      if (Hash[id[first]] == 1) A2[++ap2] = id[first];
    S = 0;
    for (int p = 1, q = 1; p <= ap1 || q <= ap2;) {
      if (p == ap1 + 1)
        id[++S] = A2[q++];
      else if (q == ap2 + 1)
        id[++S] = A1[p++];
      else if (cmp(A1[p], A2[q]) == true)
        id[++S] = A1[p++];
      else
        id[++S] = A2[q++];
    }
    yp = 0;
    ap1 = 0, ap2 = 0;
    for (int p = 1; p <= S; p++) {
      A1[++ap1] = pot[id[p]].second + 1;
      A2[++ap2] = pot[id[p]].second - K + 1;
    }
    for (int p = 1, q = 1; p <= ap1 || q <= ap2;) {
      if (p == ap1 + 1)
        Y[++yp] = A2[q++];
      else if (q == ap2 + 1)
        Y[++yp] = A1[p++];
      else if (A1[p] < A2[q])
        Y[++yp] = A1[p++];
      else
        Y[++yp] = A2[q++];
    }
    yp = 1;
    for (int p = 2; p <= S * 2; p++)
      if (Y[p] != Y[p - 1]) Y[++yp] = Y[p];
    int LL = 1, RR = 0;
    for (int p = 1; p <= yp; p++) {
      for (; RR < S && pot[id[RR + 1]].second <= Y[p] + K - 1; RR++)
        ;
      for (; LL <= S && pot[id[LL]].second < Y[p]; LL++)
        ;
      if (RR - LL + 1 >= 1)
        Ans[RR - LL + 1] += (long long)(X[i + 1] - X[i]) * (Y[p + 1] - Y[p]);
    }
  }
  for (int i = 1; i <= N; i++) printf("%I64d ", Ans[i]);
  return 0;
}
