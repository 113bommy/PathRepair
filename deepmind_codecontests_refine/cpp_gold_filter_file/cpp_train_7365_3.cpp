#include <bits/stdc++.h>
int L, A, B;
double F(double x) {
  double a = L * cos(x), b = L * sin(x);
  return (B * a + A * b - a * b) / L;
}
double calc() {
  if (A > B) std::swap(A, B);
  if (L <= A) return L;
  if (L <= B) return A;
  double l = 0, r = 3.14159265358979323846 / 2;
  for (; r - l > 1e-9;) {
    double ll = l + (r - l) / 3, rr = r - (r - l) / 3;
    if (F(ll) - F(rr) > 1e-9)
      l = ll;
    else
      r = rr;
  }
  return F(l);
}
int main() {
  scanf("%d%d%d", &A, &B, &L);
  double x = calc();
  if (x < 1e-7)
    puts("My poor head =(");
  else
    printf("%.9lf\n", x);
}
