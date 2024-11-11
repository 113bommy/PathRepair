#include <bits/stdc++.h>
using namespace std;
int uppbound(int *len, int k, int N) {
  int a = 0;
  int b = N;
  int c = (a + b) / 2;
  while (a != b) {
    if (len[c] >= k) {
      b = c;
    } else {
      a = c + 1;
    }
    c = (a + b) / 2;
  }
  return b;
}
void NVP(int *len, int k, int N) {
  int a = uppbound(len, k, N);
  len[a] = k;
}
int main() {
  int N;
  scanf("%d", &N);
  int *mas = new int[N];
  for (int i = 0; i < N; i++) scanf("%d", &mas[i]);
  int *len = new int[N + 1];
  for (int i = 0; i <= N; i++) {
    len[i] = 1000001;
  }
  len[0] = -1000001;
  for (int i = 0; i < N; i++) {
    NVP(len, mas[i], N);
  }
  int i = 0;
  while ((len[i] != 1000001) && (i <= N)) {
    i++;
  }
  cout << i - 1;
}
