#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fi first
#define se second
using namespace std;
template<class T> void rd(T &x) {
	x=0; int f=1,ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=getchar();}
	x*=f;
}
template<class T> inline bool Cmin(T &x,T y) {return x>y?x=y,1:0;}
const int inf=1e9;
const int maxn=5000+5;
int n; char s[maxn],t[maxn];
vector< pair<int,int> > S,T;
int sol(int a,int b) {
	int an=0;
	while(S[a].fi!=n||T[b].fi!=n) an+=abs(S[a++].fi-T[b++].fi);
	return an;
}
void init(char *s,vector< pair<int,int> > &S) {
	for(int i=0;i<n;++i) S.push_back(make_pair(0,i&1));
	if((n&1)==(s[1]=='1')) S.push_back(make_pair(0,n&1));
	for(int i=1;i<n;++i) if(s[i]!=s[i+1]) {
		int c=S.back().se^1; 
		S.push_back(make_pair(i,c));
	}
	for(int i=0;i<2*n;++i) {
		int c=S.back().se^1;
		S.push_back(make_pair(n,c));
	}
}
int main() {
	rd(n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	init(s,S),init(t,T);
	int an=inf;
	for(int i=0;i<=n;++i) if(S[i].se==T[n].se) Cmin(an,sol(i,n));
	for(int i=0;i<=n;++i) if(S[n].se==T[i].se) Cmin(an,sol(n,i));
	printf("%d\n",an);
	return 0;
}