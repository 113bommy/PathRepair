#include <bits/stdc++.h>
using namespace std;
struct pont {
  long long x, y;
};
long long N, M, K, tart, megy, aa, bb, mini;
pont p[500];
long long ki1[500];
long long ki2[500];
pair<long long, long long> t[1000];
set<pair<pair<long long, long long>, long long> > szet;
long long be(long long x, long long y) {
  if (x == y) {
    return (x);
  }
  long long h = (x + y) / 2;
  mini = 0;
  for (long long i = 0; i < K; i++) {
    t[i].first = p[ki1[i]].x - h;
    t[i].second = ki1[i];
    t[i + K].first = p[ki1[i]].x + h + 1;
    t[i + K].second = ki1[i];
  }
  sort(t, t + 2 * K);
  tart = 0;
  megy = max((long long)1, t[0].first);
  aa = 2000000000;
  if (megy > 1) {
    aa = 1;
  }
  bb = -1;
  long long volt = -1;
  bool elso = true;
  while (tart < 2 * K) {
    while (tart < 2 * K && t[tart].first <= megy) {
      if (t[tart].first > p[t[tart].second].x) {
        szet.erase({{p[t[tart].second].y - h, p[t[tart].second].y + h},
                    t[tart].second});
      } else {
        szet.insert({{p[t[tart].second].y - h, p[t[tart].second].y + h},
                     t[tart].second});
      }
      tart++;
    }
    long long ok = 1;
    for (pair<pair<long long, long long>, long long> i : szet) {
      if (i.first.first <= ok) {
        ok = max(ok, i.first.second + 1);
      }
    }
    if (elso) {
      elso = false;
      if (megy <= N) {
        bb = megy - 1;
      } else {
        bb = N;
      }
    }
    if (ok <= M) {
      aa = min(aa, megy);
      if (megy <= N) {
        elso = true;
        volt = megy;
      }
    }
    if (tart < 2 * K) {
      megy = t[tart].first;
    }
  }
  if (elso) {
    bb = N;
  }
  if (bb != -1) {
    mini = bb - aa;
  }
  for (long long i = 0; i < K; i++) {
    t[i].first = p[ki2[i]].y - h;
    t[i].second = ki2[i];
    t[i + K].first = p[ki2[i]].y + h + 1;
    t[i + K].second = ki2[i];
  }
  sort(t, t + 2 * K);
  tart = 0;
  megy = max((long long)1, t[0].first);
  aa = 2000000000;
  if (megy > 1) {
    aa = 1;
  }
  bb = -1;
  volt = -1;
  elso = true;
  while (tart < 2 * K) {
    while (tart < 2 * K && t[tart].first <= megy) {
      if (t[tart].first > p[t[tart].second].y) {
        szet.erase({{p[t[tart].second].x - h, p[t[tart].second].x + h},
                    t[tart].second});
      } else {
        szet.insert({{p[t[tart].second].x - h, p[t[tart].second].x + h},
                     t[tart].second});
      }
      tart++;
    }
    long long ok = 1;
    for (pair<pair<long long, long long>, long long> i : szet) {
      if (i.first.first <= ok) {
        ok = max(ok, i.first.second + 1);
      }
    }
    if (elso) {
      elso = false;
      if (megy <= M) {
        bb = megy - 1;
      } else {
        bb = M;
      }
    }
    if (ok <= N) {
      aa = min(aa, megy);
      if (megy <= M) {
        elso = true;
        volt = megy;
      }
    }
    if (tart < 2 * K) {
      megy = t[tart].first;
    }
  }
  if (elso) {
    bb = M;
  }
  if (bb != -1) {
    mini = max(mini, bb - aa);
  }
  if (2 * h < mini) {
    return (be(h + 1, y));
  } else {
    return (be(x, h));
  }
}
bool kis1(long long x, long long y) { return (p[x].x < p[y].x); }
bool kis2(long long x, long long y) { return (p[x].y < p[y].y); }
int main() {
  cin >> N >> M >> K;
  for (long long i = 0; i < K; i++) {
    cin >> p[i].x >> p[i].y;
    ki1[i] = i;
    ki2[i] = i;
  }
  sort(ki1, ki1 + K, kis1);
  sort(ki2, ki2 + K, kis2);
  cout << be(0, max(N, M)) << endl;
  return 0;
}
