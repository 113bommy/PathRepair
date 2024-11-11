#include <iostream>
#include <complex>
#include <cmath>
#include <cstdio>
using namespace std;
typedef complex<double> xy_t;
xy_t P[110];

double cross_product(xy_t a , xy_t b){
	return (conj(a)*b).imag();
}

int main(){
	int i,n;
	double x,y,area;
	scanf("%d\n",&n);
	for(i=0;i<n;i++){
		scanf("%lf %lf\n",&x,&y);
		P[i]= xy_t(x,y);
	}//読み込み

	double areasum = 0.0;
	for(i=2;i<n;i++){
		area = cross_product(P[i]-P[0],P[i-1]-P[0])/2;
		areasum += area;
	}

	areasum = fabs(areasum);
	printf("%.1f\n",areasum);
	return 0;	

}