#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<set>
#include<map>
#include<vector>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)((x).size()))
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double DB;
const DB pi=acos(-1.0);
const int N=110000;
int go[N<<2][26];
int node=1;
int sz[N<<2];
int n,Q;
struct query{
	int id;
	char d[30];
}qq[N];
char str[1010000];
int tot=0;
int st[N];
int ed[N];
int end[N<<2];
vector<int>que[N];
int ans[N];
int gtw[26][26];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%s",str+tot+1);
		st[i]=tot+1;
		ed[i]=st[i]+strlen(str+st[i])-1;
		tot=ed[i]+3;
		int now=1;
		rep(j,st[i],ed[i]){
			if(!go[now][str[j]-'a'])go[now][str[j]-'a']=++node;
			now=go[now][str[j]-'a'];
			sz[now]++;
		}
		end[now]++;
	}
	scanf("%d",&Q);
	rep(i,1,Q){
		int k;scanf("%d",&k);
		scanf("%s",qq[i].d+1);
		que[k].pb(i);
	}
	rep(i,1,n){
		memset(gtw,0,sizeof gtw);
		
		int now=1;
		int rr=0;
		rep(j,st[i],ed[i]){
			int dd=str[j]-'a';
			rep(k,0,25)if(go[now][k])if(k^dd){
				gtw[dd][k]+=sz[go[now][k]];
			}
			rr+=end[now];
			now=go[now][dd];
		}
		
		rep(j,0,que[i].size()-1){
			int xx=que[i][j];
			ans[xx]=1+rr;
			rep(d,0,25)rep(l,d+1,25)
			ans[xx]+=gtw[qq[xx].d[l]-'a'][qq[xx].d[d]-'a'];
		}
	}
	rep(i,1,Q)printf("%d\n",ans[i]);
	return 0;
}

