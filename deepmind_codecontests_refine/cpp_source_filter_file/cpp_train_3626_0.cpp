#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
bool vh[1000005],vw[1000005],ban[65][65];
int bh[1000005],bw[1000005],nh[1000005];
int nw[1000005],h,w,n,x[31],y[31],c1=0,c2=0;
int kh[105],kw[105],wgt[65][65],dis[65][65];
int que[10005][2],l=1,r=0;
inline int mul(int a,int b){
	return 1ll*a*b%mod;
}

inline int sub(int a,int b){
	return(a-b<0?a-b+mod:a-b);
}

inline bool ok(int a,int b){
	if(a<=0||a>c1||b<=0||b>c2||ban[a][b])
	return 0;
	return 1;
}

int main(){
	int i,j,k,l,ans=0;
	scanf("%d%d%d",&h,&w,&n);
	for(i=1;i<=n;++i){
		scanf("%d%d",&x[i],&y[i]);
		++x[i];++y[i];
		++nh[x[i]];++nw[y[i]];
		vh[x[i]]=vw[y[i]]=1;
	}
	bh[1]=++c1;++kh[1];
	int lo=0,tot=mul(h,w)-n;
	if(tot<0) tot+=mod;
	for(i=2;i<=h;++i){
		lo+=(w-nh[i-1]);
		if(lo>=mod)lo-=mod;
		if((!vh[i-1])&&(!vh[i])){
			ans+=mul(lo,sub(tot,lo));
			if(ans>=mod)ans-=mod;
			bh[i]=bh[i-1];++kh[c1];
		}else{
			bh[i]=++c1;
			kh[c1]=1;
		}
	}
	bw[1]=++c2;++kw[1];
	lo=0;tot=mul(h,w)-n;
	if(tot<0)tot+=mod;
	for(i=2;i<=w;++i){
		lo+=(h-nw[i-1]);
		if(lo>=mod)lo-=mod;
		if((!vw[i-1])&&(!vw[i])){
			ans+=mul(lo,sub(tot,lo));
			if(ans>=mod)ans-=mod;
			bw[i]=bw[i-1];++kw[c2];
		}else{
			bw[i]=++c2;
			kw[c2]=1;
		}
	}
	for(i=1;i<=c1;++i){
		for(j=1;j<=c2;++j){
			wgt[i][j]=mul(kh[i],kw[j]);
		}
	}
	for(i=1;i<=n;++i){
		ban[bh[x[i]]][bw[y[i]]]=1;
	}
	ans<<=1;
	if(ans>=mod)ans-=mod;
	fo(i=1;i<=c1;++i){
		for(j=1;j<=c2;++j){
			if(ban[i][j])continue;
			l=1;r=0;que[++r][0]=i;
			que[r][1]=j;
			memset(dis,0x7f,sizeof(dis));
			dis[i][j]=0;
			while(l<=r){
				int a=que[l][0],b=que[l][1];
				++l;
				if(ok(a-1,b)&&
				dis[a-1][b]>dis[a][b]+1){
					dis[a-1][b]=dis[a][b]+1;
					que[++r][0]=a-1;
					que[r][1]=b;
				}
				if(ok(a+1,b)&&
				dis[a+1][b]>dis[a][b]+1){
					dis[a+1][b]=dis[a][b]+1;
					que[++r][0]=a+1;
					que[r][1]=b;
				}
				if(ok(a-1,b)&&
				dis[a-1][b]>dis[a][b]+1){
					dis[a-1][b]=dis[a][b]+1;
					que[++r][0]=a-1;
					que[r][1]=b;
				}
				if(ok(a,b-1)&&
				dis[a][b-1]>dis[a][b]+1){
					dis[a][b-1]=dis[a][b]+1;
					que[++r][0]=a;
					que[r][1]=b-1;
				}
				if(ok(a,b+1)&&
				dis[a][b+1]>dis[a][b]+1){
					dis[a][b+1]=dis[a][b]+1;
					que[++r][0]=a;
					que[r][1]=b+1;
				}
			}
			int tp=0;
			for(k=1;k<=c1;++k){
				for(l=1;l<=c2;++l){
					if(ban[k][l])continue;
					int x=dis[k][l];
					tp+=mul(x,wgt[k][l]);
					if(tp>=mod)tp-=mod;
				}
			}
			tp=mul(tp,wgt[i][j]);
			ans+=tp;
			if(ans>=mod)ans-=mod;
		}
	}
	if(ans&1)ans+=mod;
	printf("%d\n",ans>>1);
	return 0;
}