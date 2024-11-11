#include <cstdio>
#include <complex>
using namespace std;

typedef complex<double> xy_t;

xy_t P[110];

int main(){
  int N;
  scanf("%d", &N);
  for (int i=0; i<N; i++){
    double x, y;
    scanf("%lf %lf", &x, &y)
    P[i] = xy_t(x,y);
  }
  double sum = 0.0;
  for (int i=2; i<N; ++i){
    xy_t a=P[0], b=P[i-1], c=P[i];
    sum += 0.5*((b.real()-a.real())*(c.imag()-a.imag())
		-(b.imag()-a.imag())*(c.real()-a.real()));
  }
  printf("%.6f\n", sum);
  return 0;
}