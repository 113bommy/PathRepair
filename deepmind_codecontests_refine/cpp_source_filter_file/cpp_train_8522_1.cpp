#include <iostream>
#include <cstdio>

using namespace std;

int main (void) {
  int a, b;
  double res;

  cin >> a >> b;

  res = a * b / 3.305785;
  
  printf("%.6lf\n", res)
  
  return 0;
}