#include<bits/stdc++.h>
using namespace std;

int main(){


int A,B,M;
cin>>A>>B>>M;


int amin=100000;
int bmin=100000;

int a[A],b[B];
int x[M],y[M],c[M];
int i,j,k,q,w;

for(i=0;i<A;++i){cin>>a[i];if(a[i]<amin)amin=a[i]};
for(j=0;j<B;++j){cin>>b[j];if(a[j]<bmin)bmin=b[j]}
for(k=0;k<M;++k)cin>>x[k]>>y[k]>>c[k];


int cost[M];
int f=amin+bmin;

for(int l=0;l<M;l++){

	w=x[l];
	q=y[l];
	cost[l]=a[w]+b[q]-c[l];
	if(cost[l]<f){f=cost[l];}
}

cout<<f<<endl;
}