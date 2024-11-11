#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
const int N=2e5+5;
set<int>se[N];
typedef set<int>::iterator it;
int n,now,v[N],c[N],b[N],nex[N],head[N];
struct each{
	int a,id;
}a[N];
queue<int>que;
inline int read(){
	register int x=0;
	register char ch=getchar();
	while(ch<'0'||ch>'9')	ch=getchar();
	while(ch>='0'&&ch<='9')	x=x*10+(ch^48),ch=getchar();
	return x;
}
int get(int x){
	int last=-1;
	it i=se[x].begin();
	for(;i!=se[x].end();++i)
		if(last+1==*i)	++last;
		else	break;
	return ++last;
}
int vis[N],tm[N],p[N];
int main(){
	//freopen("graph.out","w",stdout);
	//freopen("graph.in","r",stdin);

	n=read();
	for(register int i=1;i<=n;i++)
		++b[p[i]=read()];
	for(register int i=1;i<=n;i++)
		if(!b[i])	que.push(i);
	while(!que.empty()){
		int x=que.front(),k=get(x);
		que.pop(),se[p[x]].insert(k);
		if(!(--b[p[x]]))	que.push(p[x]);
	}
	int st;
	for(int i=1;i<=n;i++)
		if(b[i]){
			st=i,que.push(i);
			break;
		}
	while(!que.empty()){
		int x=que.front();
		que.pop(),tm[x]=get(x);
		if(se[p[x]].count(tm[x]))	vis[x]=1;
		se[p[x]].insert(tm[x]);
		if(p[x]==st){
			if(tm[x]==tm[st])	break;
			else{
				puts("POSSIBLE");
				return 0;
			}
		}
		que.push(p[x]);
	}
	for(int i=1;i<=n;i++)
		if(b[i]&&!vis[x])	se[p[i]].erase(tm[i]);
	int end=tm[st];
	que.push(st),se[st].insert(end);
	while(!que.empty()){
		int x=que.front();
		que.pop(),tm[x]=get(x);
		se[p[x]].insert(tm[x]);
		if(p[x]==st){
			if(tm[x]!=end)	break;
			else{
				puts("POSSIBLE");
				return 0;
			}
		}
		que.push(p[x]);
	}
	puts("IMPOSSIBLE");
	return 0;
}