#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
void __never(int a) { printf("\nOPS %d", a); }
int n;
int A[1000100];
int B[1000100];
int C[1000100];
int D[1000100];
void sol() {
  for (int a = (1); a <= (n); a++) C[B[a]] = A[a];
  D[0] = 1000000000;
  int i = 0;
  for (int a = (1); a <= (n); a++) {
    int mi = 0, ma = i;
    while (1) {
      if (ma == mi) {
        if (mi == i) i++;
        D[mi + 1] = max(D[mi + 1], C[a]);
        break;
      }
      int sr = ((mi + ma) >> 1);
      if (D[sr + 1] < C[a])
        ma = sr;
      else
        mi = sr + 1;
    }
  }
  cout << i;
}
int main() {
  cin >> n;
  for (int a = (1); a <= (n); a++) {
    int x;
    scanf("%d", &x);
    A[a] = x;
  }
  for (int a = (1); a <= (n); a++) {
    int x;
    scanf("%d", &x);
    B[a] = x;
  }
  sol();
  return 0;
}
