#include<bits/stdc++.h>
#define ll long long
#define N 200010
#define INF 1e18
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
ll n,l,a[N],b[N],sa[N],sb[N],ansn;
ll getans(int x){
	ll sum=0;
	int y=n-x;
	if (x<=y){sum=(sa[x]+sb[x+x]-sb[x])*2-a[x];}
	else{sum=(sa[x]-sa[x-y-1]+sb[n]-sb[x])*2-a[x];}
	return sum;
}
int main(){
	read(l);read(n);
	for (int i=1;i<=n;i++)read(a[i]);
	for (int i=1;i<=n;i++)b[i]=l-a[i];
	for (int i=1;i<=n;i++)sa[i]=sa[i-1]+a[i],sb[i]=sb[i-1]+b[i];
	for (int i=1;i<=n;i++){ansn=max(ansn,getans(i));}
	reverse(a+1,a+n+1);reverse(b+1,b+n+1);
	for (int i=1;i<=n;i++)swap(a[i],b[i]);
	for (int i=1;i<=n;i++)sa[i]=sa[i-1]+a[i],sb[i]=sb[i-1]+b[i];
	for (int i=1;i<=n;i++){ansn=max(ansn,getans(i));}
	cout<<ansn<<endl;
	return 0;
}