#include <bits/stdc++.h>
#include<iostream>
#include<ostream>
using namespace std;
int main(){
	int n,m;
	double sum=0;
	cin>>n>>m;
	double b[n+1];
	b[0]=0;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		b[i]=(b[i]+1)/2;
		b[i]+=b[i-1];
		if(i>=m){
			sum=max(sum,b[i]-b[i-m]);
		}
	}
	cout<<fixed<<setprecision(12)<<sum;
	return 0;
}