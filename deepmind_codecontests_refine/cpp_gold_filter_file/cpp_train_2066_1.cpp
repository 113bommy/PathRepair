#include<set>
#include<map>
//#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=2e6+19;
const int p=1e9+7;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

int fac[N],inv[N];
int x1,x2,x3,x4,x5,x6;
int y1,y2,y3,y4,y5,y6;
int ans,tmp;

int C(int n,int m){
	return 1ll*fac[n]*inv[m]%p*inv[n-m]%p;
}
int F(int a,int b,int c,int d){
	assert(a<=c&&b<=d);
	return C(c-a+d-b,c-a);
}
void Work(int a,int b,int c,int d,int f){
	tmp=0;
	For(i,y3,y4+1){
		tmp=(tmp-1ll*(x3+i)*F(x3,i,c,d)%p*F(a,b,x3-1,i))%p;
		tmp=(tmp+1ll*(x4+i+1)*F(a,b,x4,i)%p*F(x4+1,i,c,d))%p;
	}
	For(i,x3,x4+1){
		tmp=(tmp-1ll*(y3+i)*F(i,y3,c,d)%p*F(a,b,i,y3-1))%p;
		tmp=(tmp+1ll*(y4+i+1)*F(a,b,i,y4)%p*F(i,y4+1,c,d))%p;
	}
	tmp=(tmp+p)%p;
	if (f==1) ans=(ans+tmp)%p;else ans=(ans-tmp+p)%p;
}

int main(){
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	inv[N-1]=Pow(fac[N-1],p-2);
	for (int i=N-1;i;i--) inv[i-1]=1ll*inv[i]*i%p;
	x1=IN(),x2=IN(),x3=IN(),x4=IN(),x5=IN(),x6=IN();
	y1=IN(),y2=IN(),y3=IN(),y4=IN(),y5=IN(),y6=IN();
	
	Work(x1-1,y1-1,x6+1,y6+1,1);
	Work(x1-1,y2,x6+1,y6+1,-1);
	Work(x2,y1-1,x6+1,y6+1,-1);
	Work(x2,y2,x6+1,y6+1,1);
	
	Work(x1-1,y1-1,x5,y6+1,-1);
	Work(x1-1,y2,x5,y6+1,1);
	Work(x2,y1-1,x5,y6+1,1);
	Work(x2,y2,x5,y6+1,-1);
	
	Work(x1-1,y1-1,x6+1,y5,-1);
	Work(x1-1,y2,x6+1,y5,1);
	Work(x2,y1-1,x6+1,y5,1);
	Work(x2,y2,x6+1,y5,-1);
	
	Work(x1-1,y1-1,x5,y5,1);
	Work(x1-1,y2,x5,y5,-1);
	Work(x2,y1-1,x5,y5,-1);
	Work(x2,y2,x5,y5,1);
	printf("%d\n",ans);
}