#include <cstdio>
#include <utility>
#include <queue>
using namespace std;
int i,n,L,t,tr[100002],s;
int main(){
	typedef pair<int,int>pii;
	priority_queue<pii> qu;
	pii p;
	
	for(scanf("%d%d",&n,&L);i++<n;)scanf("%d",tr+i);

	for(;--i;)
		tr[i]>tr[i-1]&tr[i]>tr[i+1]?
			qu.push(pii(tr[i]-L,i)),
			tr[i]=L:0;

	for(;!qu.empty();		n&&n!=L&n>tr[s+2]?
			qu.push(pii(t-L+n,s+1)),
			tr[s+1]=L
		:0)
		p=qu.top(),
		qu.pop(),
		
		t=p.first,
		tr[s=p.second]=0,
		
		n=tr[s-1],
		n&&n!=L&n>tr[s-2]?
			qu.push(pii(t-L+n,s-1)),
			tr[s-1]=L
		:0,
		n=tr[s+1];

	
	printf("%d\n",-t);
}