#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
const ll mod=998244353;
ll n,ri,le,s0,f[1000005];
struct node{
	int x,y;
	bool operator<(node b)const{
		return x-y>b.x-b.y;
	}
}a[1000005];
char s[1000005];
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		ll l=0,r=0;
		scanf("%s",s+1);
		for(int j=1;s[j];j++)
			if(s[j]=='(')l++;
			else{
				if(l)l--;
				else r++;
			}
		if(!l and r)ri+=r;
		else if(l and !r)le+=l;
		else a[i]=(node){l,r};	
		s0+=l-r;
	}
	if(s0!=0)return puts("No"),0;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(le<a[i].y)
			return puts("No"),0;
		le-=a[i].y-a[i].x;
	}
	if(le!=ri)puts("No");
	else puts("Yes");
	return 0;
}