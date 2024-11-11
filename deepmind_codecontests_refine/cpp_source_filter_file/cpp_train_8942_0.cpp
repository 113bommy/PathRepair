#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
#include<cstdlib>
#include<cmath>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)

int cont;
void saiki(double rest,int a, int n, int st, vector<int>& bin){
	
	if(fabs(rest)<0.0000001){cont++; return;}
	if(bin.size()==n)return;
	if(rest<0)break;
	
	int sum = 1;
	rep(i,bin.size())sum*=bin[i];
	
	for(int i=st;;i++){
		if(sum*i<=a){
			bin.push_back(i);
			saiki(rest-1.0/i, a, n, i, bin);
			bin.pop_back();
		}else{
			break;
		}
	}
}

int main(){
	while(1){
		int p,q,a,n;
		cin>>p>>q>>a>>n;
		cont = 0;
		
		if(n==0)break;
		
		vector<int> bin;
		int st = 1;
		double rest = (double)p/q;
		saiki(rest,a,n,st,bin);
		
		printf("%d\n",cont);
	}
}