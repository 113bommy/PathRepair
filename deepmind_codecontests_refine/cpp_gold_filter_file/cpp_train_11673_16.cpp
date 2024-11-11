#include <bits/stdc++.h>
int N, M, H;
int Other, This;
int main() {
  scanf("%d%d%d", &N, &M, &H);
  for (int i = 1; i <= M; i++) {
    int T;
    scanf("%d", &T);
    if (i == H)
      This += T;
    else
      Other += T;
  }
  double Ans = 1;
  if (N > This + Other)
    Ans = -1;
  else {
    for (int i = 0; i < N - 1; i++)
      Ans = Ans * (Other - i) / (Other + This - i - 1);
    Ans = 1 - Ans;
  }
  printf("%.10lf\n", Ans);
  return 0;
}
