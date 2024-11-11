#include<bits/stdc++.h>
using namespace std;
int n,a[200010],b[200010];
long long ans=0;
bool w=false;
struct node{
	int pos,val;
	bool operator <(const node &b)const{
		return val<b.val;
	}
};
priority_queue<node>q;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		node tmp={i,b[i]};
		q.push(tmp);
	}
	while(q.size()){
		node now=q.top();q.pop();
		int l=(now.pos-2+n)%n+1,r=now.pos%n+1;
		if(b[now.pos]==a[now.pos]) continue;
		if(b[now.pos]-b[l]-b[r]<a[now.pos]){
			puts("-1");
			return 0;
		}
		int d=b[now.pos]-a[now.pos];
		ans+=d/(b[l]+b[r]);
		b[now.pos]=d%(b[l]+b[r])+a[now.pos];
		if(b[now.pos]==a[now.pos]) continue;
		node tmp={now.pos,b[now.pos]};
		q.push(tmp);
	}
	printf("%lld\n",ans); 
}