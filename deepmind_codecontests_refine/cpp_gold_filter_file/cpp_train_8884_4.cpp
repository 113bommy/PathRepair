#include <bits/stdc++.h>
using namespace std;
int n, cnt = 1, Son[2][1000006];
int K[3][1000006], M[202], F[5];
char S[1000006];
int Built(int now) {
  int i = cnt, k;
  ++cnt, Son[0][i] = cnt;
  if (S[now] == '(')
    now = Built(now + 1) + 1;
  else {
    K[0][cnt] = K[1][cnt] = K[2][cnt] = 0;
    K[M[(int)S[now]]][cnt] = 1;
    ++now;
  }
  k = S[now], ++now;
  ++cnt, Son[1][i] = cnt;
  if (S[now] == '(')
    now = Built(now + 1) + 1;
  else {
    K[0][cnt] = K[1][cnt] = K[2][cnt] = 0;
    K[M[(int)S[now]]][cnt] = 1;
    ++now;
  }
  if (k == '|') {
    K[0][i] = K[0][Son[0][i]] & K[0][Son[1][i]];
    K[1][i] = K[1][Son[0][i]] | K[1][Son[1][i]];
    if (K[0][Son[1][i]]) K[2][i] = K[2][Son[0][i]];
    if (K[0][Son[0][i]]) K[2][i] |= K[2][Son[1][i]];
    if ((K[2][Son[0][i]] & 1) && (K[2][Son[1][i]] & 1)) K[2][i] |= 1;
    if ((K[2][Son[0][i]] & 2) && (K[2][Son[1][i]] & 2)) K[2][i] |= 2;
    if (K[2][Son[0][i]] & K[2][Son[1][i]]) K[1][i] = 1;
  } else if (k == '&') {
    K[0][i] = K[0][Son[0][i]] | K[0][Son[1][i]];
    K[1][i] = K[1][Son[0][i]] & K[1][Son[1][i]];
    if (K[1][Son[1][i]]) K[2][i] |= K[2][Son[0][i]];
    if (K[1][Son[0][i]]) K[2][i] |= K[2][Son[1][i]];
    if ((K[2][Son[0][i]] & 1) && (K[2][Son[1][i]] & 1)) K[2][i] |= 1;
    if ((K[2][Son[0][i]] & 2) && (K[2][Son[1][i]] & 2)) K[2][i] |= 2;
    if (K[2][Son[0][i]] & K[2][Son[1][i]]) K[1][i] = 1;
  } else {
    K[0][i] = (K[0][Son[0][i]] & K[0][Son[1][i]]) |
              (K[1][Son[0][i]] & K[1][Son[1][i]]);
    K[1][i] = (K[0][Son[0][i]] & K[1][Son[1][i]]) |
              (K[1][Son[0][i]] & K[0][Son[1][i]]);
    if (K[0][Son[1][i]]) K[2][i] |= K[2][Son[0][i]];
    if (K[0][Son[0][i]]) K[2][i] |= K[2][Son[1][i]];
    if (K[1][Son[1][i]]) K[2][i] |= F[K[2][Son[0][i]]];
    if (K[1][Son[0][i]]) K[2][i] |= F[K[2][Son[1][i]]];
    if (K[2][Son[0][i]] && K[2][Son[1][i]]) K[1][i] = K[0][i] = 1;
  }
  return now;
}
int main() {
  F[1] = 2, F[2] = 1, F[3] = 3;
  M['1'] = 1, M['?'] = 2;
  scanf("%d", &n);
  scanf("%s", S + 1);
  Built(1);
  if (K[2][1])
    return puts("YES"), 0;
  else
    puts("NO");
  return 0;
}
