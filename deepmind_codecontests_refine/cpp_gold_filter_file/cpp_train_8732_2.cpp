#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		double x,y,b,p,suma=0,sumb=0;
		cin>>x>>y>>b>>p;
		suma=x*b+y*p;
		if(b>=5&&p>=2) suma=suma*4/5;
		if(b<5) b=5;
		if(p<2) p=2;
		sumb=(x*b+y*p)*4/5;
		cout<<min(suma,sumb)<<endl;
	}
	return 0;
}