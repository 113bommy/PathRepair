#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re //register
#define I inline int
#define V inline void
#define B inline bool
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define REP(a,b) for(rnt _=0;x=a[_],_<b;_++)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	rnt _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=2e5+2;
int n,a[N],siz[N];
struct node{
	int p,w;
	B operator<(const node&u)const{
		return p==u.p?w<u.w:p<u.p;
	}
}dp[N][10],tmp[N];
I max(const int&x,const int&y){return x>y?x:y;}
node mk(rnt x,rnt y){return (node){max(0,x),y};}
V input(){n=getint();FOR(i,1,n)a[i]=getint();}
V init(){n=unique(a,a+n+2)-a-1,dp[0][0]=mk(0,0),siz[0]=1;}
V work(){
	rnt d,minn,tot;node x;
	FOR(i,1,n){
		d=a[i]-a[i-1],minn=N,tot=0;
		if(d>0)REP(dp[i-1],siz[i-1])
			tmp[tot++]=mk(0,x.w+2),tmp[tot++]=mk(x.p,x.w+1),tmp[tot++]=mk(x.p+d,x.w);
		else REP(dp[i-1],siz[i-1])
			tmp[tot++]=mk(0,x.w+2),tmp[tot++]=mk(x.p+d,x.w+1),tmp[tot++]=mk(x.p,x.w);
		sort(tmp,tmp+tot);
		REP(tmp,tot)if(minn>x.w&&x.p<=a[i])
			dp[i][siz[i]++]=mk(x.p,x.w),minn=x.w;
		FOR(j,0,tot-1)tmp[j]=mk(0,0);
	}
	minn=N;
	REP(dp[n],siz[n])if(x.w<minn)minn=x.w;
	cout<<minn;
}
int main(){
	input();
	init();
	work();
	return 0;
}