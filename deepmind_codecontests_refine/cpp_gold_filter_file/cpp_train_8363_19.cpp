#include <bits/stdc++.h>
using namespace std;
static int W, c3, c4, c5, w3, w4, w5;
static int n, m, ans, A3, A4, A5;
int gcd(int A, int B, int &X, int &Y) {
  if (A == 0) {
    X = 0;
    Y = 1;
    return B;
  }
  int d = gcd(B % A, A, X, Y);
  int tmp = X;
  X = Y - X * (B / A);
  Y = tmp;
  return d;
}
int yxabs(int x) {
  if (x < 0)
    return -x;
  else
    return x;
}
void update(int x, int y, int z) {
  int w = yxabs(x * c3 - y * c4) + yxabs(x * c3 - z * c5);
  if (w < ans) {
    ans = w;
    A3 = x;
    A4 = y;
    A5 = z;
  }
}
void Sol(int A, int B, int S, int T, int W1) {
  int W2 = W - W1;
  int d = gcd(A, B, w4, w5);
  A /= d;
  B /= d;
  if (W1 % d != 0) return;
  w4 *= W1 / d;
  w5 *= W1 / d;
  w4 %= B;
  w4 += ((S - w4 + B - 1) / B) * B;
  int now = w4 * c4, t = (T - w4) / B, K = c4 * B;
  if (w4 > T) return;
  if (now >= W2)
    update(w3, w4, (W1 - now) / c5);
  else {
    if (now + K * t <= W2) {
      w4 += t * B;
      now = w4 * c4;
      update(w3, w4, (W1 - now) / c5);
    } else {
      now += (W2 - now) / K * K;
      if (now >= W2) now -= K;
      update(w3, now / c4, (W1 - now) / c5);
      now += K;
      update(w3, now / c4, (W1 - now) / c5);
    }
  }
}
int main() {
  scanf("%d%d", &n, &W);
  ans = W * 2 + 1;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (x == 3) c3++;
    if (x == 4) c4++;
    if (x == 5) c5++;
  }
  swap(c3, c4);
  for (w3 = 0; w3 * c3 <= W && (c3 != 0 || w3 != 0); w3++)
    Sol(c4, c5, 0, min((W - w3 * c3 - w3 * c5) / c4, w3), W - w3 * c3);
  if (ans <= W * 2)
    printf("%d %d %d\n", A4, A3, A5);
  else
    puts("-1");
  return 0;
}
