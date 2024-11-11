#include <bits/stdc++.h>
using namespace std;
vector<pair<long, long> > kt[451];
vector<pair<long, long> > c, C;
vector<long> all[450];
pair<short int, pair<long, long> > a[200001];
long N, i, j, i1, x, y, s, nn, K[200001], sum[451], i2;
char cc, ccc;
pair<long, long> t, t1;
long biin(pair<long, long> tt) {
  long n = 0, k = C.size(), S;
  if (nn == 0) return 0;
  if (C[nn - 1] < tt) return nn;
  while (n < k) {
    S = (n + k) / 2;
    if (C[S] == t) break;
    if (C[S] > tt)
      k = S;
    else
      n = S + 1;
  }
  while (C[S] < tt) S++;
  while ((S != 0) && (C[S - 1] >= tt)) S--;
  return S;
}
int main(void) {
  scanf("%ld", &N);
  for (j = 1; j <= N; j++) {
    scanf("\n");
    scanf("%c", &cc);
    ccc = cc;
    while (ccc != ' ') scanf("%c", &ccc);
    scanf("%ld%ld", &x, &y);
    t.first = x;
    t.second = y;
    a[j].second = t;
    if (cc == 'a') {
      c.push_back(t);
      a[j].first = 1;
    }
    if (cc == 'r') a[j].first = 2;
    if (cc == 'f') a[j].first = 3;
  }
  sort(c.begin(), c.end());
  if (c.size() != 0) C.push_back(c[0]);
  for (i = 1; i < c.size(); i++)
    if (c[i] != c[i - 1]) C.push_back(c[i]);
  nn = C.size();
  for (j = 1; j <= N; j++) {
    t = a[j].second;
    i = biin(t);
    if (i == nn) {
      printf("-1\n");
      continue;
    }
    if (a[j].first == 1) {
      K[i] = 1;
      sum[nn / 450]++;
      all[i / 450].push_back(t.second);
      i1 = all[i / 450].size() - 1;
      while ((i1 > 0) && (all[i / 450][i1] < all[i / 450][i1 - 1])) {
        x = all[i / 450][i1];
        all[i / 450][i1] = all[i / 450][i1 - 1];
        all[i / 450][i1 - 1] = x;
        i1--;
      }
    }
    if (a[j].first == 2) {
      K[i] = 0;
      sum[nn / 450]--;
      for (i1 = 0; i1 < all[i / 450].size(); i1++)
        if (all[i / 450][i1] == t.second) break;
      for (; i1 < all[i / 450].size() - 1; i1++)
        all[i / 450][i1] = all[i / 450][i1 + 1];
      all[i / 450].resize(all[i / 450].size() - 1);
    }
    if (a[j].first == 3) {
      t1.first = t.first + 1;
      t1.second = t.second + 1;
      i = biin(t1);
      for (i1 = i; i1 <= min((i / 450 + 1) * 450 - 1, nn - 1); i1++)
        if ((K[i1] != 0) && (C[i1].first >= t1.first) &&
            (C[i1].second >= t1.second))
          break;
      if ((i1 != (i / 450 + 1) * 450) && (i1 != nn)) {
        printf("%ld %ld\n", C[i1].first, C[i1].second);
        continue;
      }
      for (i1 = i / 450 + 1; i1 <= nn / 450; i1++)
        if ((sum[i1] != 0) && (all[i1][all[i1].size() - 1] > t.second)) break;
      if (i1 == nn / 450 + 1) {
        printf("-1\n");
        continue;
      }
      for (i2 = i1 * 450; i2 <= min(nn - 1, i1 * 450 + 499); i2++)
        if ((K[i2] == 1) && (C[i2].first >= t1.first) &&
            (C[i2].second >= t1.second))
          break;
      printf("%ld %ld\n", C[i2].first, C[i2].second);
    }
  }
  return 0;
}
