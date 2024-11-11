#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M, minm, maxm;
  scanf("%d %d %d %d", &N, &M, &minm, &maxm);
  int a[M];
  bool fr[107] = {0}, chk = true;
  for (int i = 0; i < M; i++) {
    scanf("%d", &a[i]);
    fr[a[i]] = true;
    if (chk && (a[i] < minm || a[i] > maxm)) chk = false;
  }
  bool dne = false;
  if (chk) {
    if ((N - M) >= 0 && fr[minm] && fr[maxm]) dne = true;
    if ((N - M) >= 1 && !fr[minm] && fr[maxm])
      dne = true;
    else if ((N - M) >= 1 && !fr[maxm] && fr[minm])
      dne = true;
    else if ((N - M) >= 2 && !fr[minm] && !fr[maxm])
      dne = true;
  }
  if (dne)
    printf("Correct\n");
  else
    printf("Incorrect\n");
  return 0;
}
