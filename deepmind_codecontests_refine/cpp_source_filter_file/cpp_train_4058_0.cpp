#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;


int s,n,t,p,m;
int blockw;
int blockt;
int minute[10081];
string wd,tim;

double check(int start){
	int i, j;
	int suc=0;
	for(i=0;i<m;i++,start+=t;){
		for(j = 0;j <= s;j++) if(!minute[(start+j)%10080]) break;
		if(j>s) suc ++;
	}
	return 1-pow(1-1/(double)p, (double)suc*n);
}

main(){
	int i,j;
	while(cin >> s >> n >> t >> wd >> tim >> p >> m, s){
		fill(minute, &minute[10080], 0);
		if(wd=="All") blockw = (1<<7)-1;
		else blockw = 1;
		if(tim=="Night") blockt = 1;
		else if(tim=="Day") blockt = 2;
		else blockt = 3;
		for(i=0;i<10080;i++){
			if((blockw & (1 << i/1440)) == 0) continue;
			if((blockt & (1 << ((i/360+1)%4/2))) == 0) continue;
			minute[i] = 1;
		}
		double ans = 0;
		for(i=0;i<1440;i++){
			double ret = check(i);
			ans = max(ans, ret);
		}
		printf("%.10f\n", ans);
	}
	return 0;
}