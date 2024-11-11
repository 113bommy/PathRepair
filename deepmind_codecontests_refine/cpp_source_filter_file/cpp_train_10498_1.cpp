#include<bits/stdc++.h>
#define double long double
using namespace std;
const int N=200005;
struct node{
	int x,y;
	bool operator <(const node &a)const{
		return x<a.x;
	}
}a[N];
int q[N],t;
int sx,sy,tx,ty;
int find(int k){
	int l=1,r=t+1;
	while (l<r){
		int mid=(l+r)/2;
		if (k<q[mid]) r=mid;
		else l=mid+1;
	}
	return l;
}
void add(int k){
	int x=find(k);
	q[x]=k; t=max(t,x);
}
int main(){
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	if (sx>tx) swap(sx,tx),swap(sy,ty);
	int num,n=0; scanf("%d",&num);
	while (num--){
		int x,y;
		scanf("%d%d",&x,&y);
		if (x>=sx&&x<=tx) a[++n]=(node){x,y};
	}
	sort(a+1,a+n+1);
	if (sy<ty){
		for (int i=1;i<=n;i++)
			if (a[i].y>=sy) add(a[i].y);
	}
	else{
		swap(sy,ty);
		for (int i=n;i;i--)
			if (a[i].y>=sy) add(a[i].y);
	}
	int k=find(ty)-1;
	int v=k>=min(tx-sx,ty-sy)+1);
	double pi=acos(-1);
	printf("%.15Lf\n",(tx+ty-sx-sy)*100.0+k*(5.0*pi-20.0)+v*5.0*pi);
} 