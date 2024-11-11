#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[6];
	for(int b=0;b<3;b++){
		for(int c=0;c<6;c++)scanf("%d",&a[c]);
		int d=(a[3]-a[0])*3600+(a[4]-a[1])*60+(a[5]-a[2]);
		printf("%d %d %d\n",d/3600,d%3600/60,d%3600%60)
	}
}