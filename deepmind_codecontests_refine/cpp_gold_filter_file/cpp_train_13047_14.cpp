#include <bits/stdc++.h>
using namespace std;
struct XD {
  int first, No;
  double second;
  bool operator<(XD A) const {
    if (first == A.first) return second < A.second;
    return first < A.first;
  }
};
int N, K, H;
XD P[100010];
int ans[100010];
bool chk(double tar) {
  ans[0] = ans[1] = -1;
  int nowpos = K;
  int nowlem = N - 1;
  while (1) {
    if (nowpos == 0 || nowlem == -1) break;
    if ((nowpos * H) / P[nowlem].second <= tar) {
      ans[nowpos] = nowlem;
      nowpos--;
    }
    nowlem--;
  }
  if (ans[1] == -1) return false;
  return true;
}
int main(void) {
  scanf("%d%d%d", &N, &K, &H);
  for (int i = 0; i < N; i++) scanf("%d", &P[i].first);
  for (int i = 0; i < N; i++) scanf("%lf", &P[i].second);
  for (int i = 0; i < N; i++) P[i].No = i;
  sort(P, P + N);
  double L, R, Mid;
  L = 0, R = 1e9;
  double tempans;
  for (int i = 0; i < 200; i++) {
    Mid = (L + R) / 2;
    if (chk(Mid)) {
      R = Mid;
      tempans = Mid;
    } else {
      L = Mid;
      tempans = Mid;
    }
  }
  chk(R);
  printf("%d", P[ans[1]].No + 1);
  for (int i = 2; i <= K; i++) printf(" %d", P[ans[i]].No + 1);
  return 0;
}
