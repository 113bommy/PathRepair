#include <bits/stdc++.h>
using namespace std;
int N;
int S[(100010 << 1)], St[(100010 << 1)], next[(100010 << 1)], R[8];
bool F[(100010 << 1)][8], exist;
int last, sz, res;
pair<int, int> G[(100010 << 1)][8];
vector<pair<int, int> > P, E;
int main() {
  scanf("%d", &N);
  res = sz = last = 0;
  E.push_back(make_pair(0, 0));
  for (int i = 1, j = 0; i <= N; i++) {
    scanf("%d", &S[i]);
    St[i] = S[i];
    if (S[i] != 0) {
      last = i, res = S[i];
      E.push_back(make_pair(S[i], i));
    }
  }
  sz = E.size() - 1;
  memset(F, false, sizeof(F));
  F[0][5] = true, exist = true;
  for (int i = 1, m = 0; i < E.size(); i++, m++) {
    int mxl, mil;
    int dn = E[i].first - E[i - 1].first - 1;
    int dl = E[i].second - E[i - 1].second - 1, tdl;
    exist = false;
    if (dn >= 0) {
      mil = dn * 2, mxl = dn * 5;
      for (int j = 1; j <= 5; j++)
        for (int k = 1; F[m][j] && k <= 5; k++)
          for (int n = max(2, j); n <= 5; n++) {
            tdl = dl - (k - 1) - (n - j);
            if (mil <= tdl && tdl <= mxl) {
              exist = F[m + 1][k] = true;
              G[m + 1][k] = (make_pair(j, n - j));
              break;
            }
          }
    } else if (dn == -1) {
      for (int j = 1; j <= 5; j++) {
        if (!F[m][j]) continue;
        if (j + dl + 1 <= 5) {
          exist = F[m + 1][j + dl + 1] = true;
          G[m + 1][j + dl + 1] = make_pair(j, dl);
        } else
          break;
      }
    }
    if (!exist) break;
  }
  int gg, ss;
  if (exist) {
    exist = false;
    if (last == N) {
      for (int i = 2; exist == false && i <= 5; i++)
        if (F[sz][i]) exist = true, gg = i;
    } else if (last < N) {
      int mxr = -1;
      for (int i = 1, l; i <= 5; i++) {
        if (!F[sz][i]) continue;
        if (i == 1) {
          l = N - last - 1;
          if (l > 1 && l / 2 > mxr)
            mxr = l / 2, gg = i, ss = 1;
          else if (l <= 1 && mxr == -1)
            mxr = 0, gg = i, ss = l;
        } else if (i > 1) {
          l = N - last;
          if (l > 1 && l / 2 > mxr)
            mxr = l / 2, gg = i, ss = 0;
          else if (l == 1 && i < 5 && mxr == -1)
            mxr = 0, gg = i, ss = 1;
        }
      }
      if (mxr >= 0) {
        exist = true;
        if (ss == 1) S[++last] = res;
        int p;
        for (p = last + 1; p + 1 <= N; p += 2) S[p] = S[p + 1] = ++res;
        if (p < N)
          S[p + 1] = res;
        else if (p == N)
          S[p] = res;
      }
    }
  }
  if (exist) {
    printf("%d\n", res);
    for (int i = sz, k = gg; i != 0; i--) {
      P.push_back(make_pair(G[i][k].second, k - 1));
      k = G[i][k].first;
    }
    for (int i = 1, j = P.size() - 1, k; j >= 0 && i < E.size(); i++, j--) {
      int st = E[i - 1].first, en = E[i].first;
      int dd = st, p = E[i - 1].second + 1;
      for (k = 1; k <= P[j].first; k++, p++) S[p] = dd;
      int dl = E[i].second - E[i - 1].second - 1 - P[j].first - P[j].second;
      int dn = en - st - 1;
      for (k = 5; dn > 0 && k > 2; k--)
        if (dn * (k - 1) <= dl && dl <= dn * k) break;
      if (dn > 0) {
        if (dn * (k - 1) == dl) {
          for (dd += 1; dd < en; dd++)
            for (int h = 1; h <= k - 1; h++, p++) S[p] = dd;
          dd--;
        } else if (dn * k == dl) {
          for (dd += 1; dd < en; dd++)
            for (int h = 1; h <= k; h++, p++) S[p] = dd;
          dd--;
        } else {
          int mm = dl - dn * (k - 1), nn = dn * k - dl, cc;
          for (dd += 1, cc = 1; cc <= nn; cc++, dd++)
            for (int h = 1; h <= k - 1; h++, p++) S[p] = dd;
          dd--;
          for (dd += 1, cc = 1; cc <= mm; cc++, dd++)
            for (int h = 1; h <= k; h++, p++) S[p] = dd;
          dd--;
        }
      }
      for (k = 1, dd += 1; dd <= en && k <= P[j].second; k++, p++) S[p] = dd;
    }
    for (int i = 1; i <= N; i++) printf("%d ", S[i]);
    printf("\n");
  } else
    printf("-1\n");
  return 0;
}
