#include <bits/stdc++.h>
using namespace std;
int za[1000005];
int main() {
  int(n), (q);
  scanf("%d%d", &(n), &(q));
  ;
  vector<int>(v);
  for (int i = (0); i < ((n)); ++i) {
    int(a);
    scanf("%d", &(a));
    ;
    (v).push_back(a);
  };
  long long int sum = 0;
  for (int i = (0); i < (n); ++i) sum += v[i];
  for (int i = (0); i < (n); ++i) v.push_back(v[i]);
  while (q--) {
    long long int b;
    scanf("%l64d", &b);
    if (b >= sum) {
      printf("1\n");
      continue;
    }
    long long int act = 0;
    int aj = 0, nxt = 0;
    while (aj != n) {
      while (act + v[nxt] <= b) {
        act += v[nxt];
        nxt++;
      }
      za[aj] = nxt;
      act -= v[aj];
      aj++;
    }
    int mini = n + 5, dla = -1;
    aj = 0;
    int ans = 0;
    vector<int> kto;
    kto.push_back(0);
    while (aj < n) {
      aj = za[aj];
      kto.push_back(aj);
      ans++;
    }
    for (int i = (0); i < (kto.size() - 1); ++i) {
      mini = min(mini, kto[i + 1] - kto[i]);
      if (mini == kto[i + 1] - kto[i]) dla = i;
    }
    for (int kk = (kto[dla]); kk < (kto[dla + 1] + 1); ++kk) {
      int k = kk % n;
      int myans = 0;
      bool okr = false;
      int ja = k;
      while (!okr || ja < k) {
        ja = za[ja];
        myans++;
        if (ja >= n && !okr) okr = true, ja = ja % n;
      }
      ans = min(ans, myans);
    }
    printf("%d\n", ans);
  }
}
