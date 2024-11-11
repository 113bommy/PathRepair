#include <complex.h>
#include <math.h>
#include <iostream>
#include <stdio.h>

using namespace std;

typedef complex<double> xy_t;

double dot_product(xy_t a, xy_t b) {
  return (conj(a)*b).real();
}

double cross_product(xy_t a, xy_t b) {
  return (conj(a)*b).imag();
}

int main() {
  xy_t P[100];
  int n;

  cin >> n;
  
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    P[i] = xy_t(x,y);
  }

  //center all coordinates based on first element
  for (int i = 1; i < n; i++) {
    P[i] -= P[0];
  }
  
  //calculate sum
  double sum = 0.0;
  for (int i = 1; i+1 < n ; i++) {
    xy_t  a = P[i] , b = P[i + 1];
    sum += cross_product(a, b) / 2.0;
  }

  printf("%.1f\n", abs(sum));
  
}