#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
long N, M;
int main(void) {
  long i, j, u, v, Icase, k = 0;
  scanf("%ld%ld", &N, &M);
  set<pair<long, long> > s;
  for (i = 1; i <= M; i++) {
    scanf("%ld%ld", &u, &v);
    s.insert(make_pair(u, v));
    s.insert(make_pair(v, u));
  }
  vector<long> Vec;
  for (i = 1; i <= N; i++) {
    Vec.push_back(i);
  }
  long Cnt = 50;
  do {
    random_shuffle(Vec.begin(), Vec.end());
    for (i = 0; i < M; i++) {
      u = Vec[i];
      v = Vec[(i + 1) % N];
      if (s.find(make_pair(u, v)) != s.end()) break;
    }
    if (i == M) {
      for (i = 0; i < M; i++) {
        u = Vec[i];
        v = Vec[(i + 1) % N];
        printf("%ld %ld\n", u, v);
      }
      return 0;
    }
    Cnt--;
    if (!Cnt) break;
  } while (Cnt);
  printf("-1\n");
  return 0;
}
