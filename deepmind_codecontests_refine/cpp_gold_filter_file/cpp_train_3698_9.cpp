#include <bits/stdc++.h>
using namespace std;
int maxN = 2e+5 + 8;
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
void solve() {
  int N;
  cin >> N;
  vector<char> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  int r, g, b;
  r = g = b = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] == 'R') r += 1;
    if (A[i] == 'B') b += 1;
    if (A[i] == 'G') g += 1;
  }
  int R = r, B = b, G = g;
  if (r > 1) r = 1;
  if (b > 1) b = 1;
  if (g > 1) g = 1;
  if (r + b + g == 3) {
    printf("BGR\n");
  } else if (r + g + b == 2) {
    if (r == 0) {
      if (B > 1 && G > 1)
        printf("BG");
      else if (G > 1)
        printf("B");
      else if (B > 1)
        printf("G");
      printf("R\n");
    }
    if (b == 0) {
      printf("B");
      if (G > 1 && R > 1)
        printf("GR");
      else if (R > 1)
        printf("G");
      else if (G > 1)
        printf("R");
      printf("\n");
    }
    if (g == 0) {
      if (B > 1 && R > 1)
        printf("BGR");
      else if (R > 1)
        printf("BG");
      else if (B > 1)
        printf("GR");
      else
        printf("G");
      printf("\n");
    }
  } else {
    if (r == 1) printf("R\n");
    if (b == 1) printf("B\n");
    if (g == 1) printf("G\n");
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1, t;
  t = T;
  while (T--) {
    solve();
  }
}
