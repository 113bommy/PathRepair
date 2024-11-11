#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[200008];int oz=0;
void out(int t,int x,int y,int z){
	if(t) putchar('+');else putchar('<');
//	if(t) a[z]=a[x]+a[y];else a[z]=(a[x]<a[y]);
oz++;
	printf(" %d %d %d\n",x-1,y-1,z-1);
}
#define n 30

int cmp(int x,int y){
	for(int i=1247;i<=1248;i++) out(0,7777,7777,i);
	out(0,1248,x,1247);
	out(1,y,1247,1247);
	out(0,5,1247,1247);	
	return 1247;
}
	int a1=100,b1=400,c1=888;int t=36666;
	void mul(int x,int p){
		while(p--) out(1,x,x,x);
	}
	void solve(int xg){
		out(0,t-1,t-1,t);
		for(int i=n;i>=0;i--) {
			out(1,t-1,t,t+1);
			out(1,t,5+i,t);
			out(0,t,xg,a1+i);
			out(1,t-1,t+1,t);
			mul(a1+i,i);
			out(1,a1+i,t,t);
			out(0,t-1,a1+i,a1+i);
		}
	//	for(int i=0;i<=n;i++) cout<<a[a1+i];cout<<"\n";
	}
signed main(){
//	cin>>a[1]>>a[2];
printf("%d\n",8996);
	out(1,1,2,3);out(0,4,3,5);
	
	out(1,1,5,1);
	out(1,2,5,2);//to use < as <=
//	cout<<a[1]<<" "<<a[2]<<"\n";
	for(int i=1;i<=n;i++) out(1,4+i,4+i,5+i);
	solve(1);swap(a1,b1);solve(2);

	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) {
		out(1,cmp(a1+i,b1+j),c1+i+j,c1+i+j);
	}
	out(0,3,3,3);
	for(int i=0;i<=n+n;i++){
		mul(c1+i,i);
		out(1,c1+i,3,3);
	}
//	cout<<oz<<"\n";
//	cout<<a[2]<<"\n";
	return 0;
}