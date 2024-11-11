#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;

int main(){
	int n;
	double total,sd,s[1001];
	while(1){
		total=0;
		sd=0;
		cin >> n;
		if(n==0){
			break;
		}
	for(i=0;i<n;i++){
	cin >> s[i];
	total += s[i];
	}
		total=total/n;
	for(i=0;i<n;i++){
		sd += pow((s[i]-total),2);
	}
	printf("%.8f\n",sqrt(sd/n));
	}
	return 0;
}