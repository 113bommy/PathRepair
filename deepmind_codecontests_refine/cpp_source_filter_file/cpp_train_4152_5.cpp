#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


int main(){
	char _;	
	int n=0;
	double x[21],y[21];
	while(cin>>x[n]>>_>>y[n])n++;
	x[n]=x[0];y[n]=y[0];
	double s=0;
	for(int i=0;i<n;i++){
		s += x[i]*y[i+1] - y[i]*x[i+1];
	}
	printf("%.6f\n",fabs(s/2));
	return 0;
}