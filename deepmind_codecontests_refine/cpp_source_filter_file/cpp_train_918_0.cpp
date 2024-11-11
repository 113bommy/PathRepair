#pragma GCC optimize(3,"Ofast")
#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
    char c=getchar();bool f=0;x=0;
    while(!isdigit(c)) f|=c=='-',c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(f) x=-x;return x;
}
template<class t> inline void write(t x){
    if(x<0) putchar('-'),write(-x);
    else{if(x>9) write(x/10);putchar('0'+x%10);}
}

const int N=2e5+5;
int n,m,ans,pn,p[N];

struct dislike{
	int l,r;
	inline operator < (const dislike &nt) const {
		if(l==nt.l) return r>nt.r;
		return l<nt.l;
	}
}a[N];

priority_queue<int,vector<int>,greater<int> > q;

signed main(){
	read(n);read(m);
	for(int i=1;i<=n;i++) read(a[i].l),read(a[i].r);
	sort(a+1,a+1+n);
	int l=1,r=m;
	for(int i=1;i<=n;i++){
		q.push(a[i].r);
		if(l<=r&&l<=a[i].l) l++;
		else{
			p[++pn]=q.top();
			q.pop();
		}
	}
	sort(p+1,p+1+pn,greater<int>());
	for(int i=1;i<=pn;i++){
		if(l<=r&&p[i]<=r) r--;
		else ans++;
	}
	write(ans);
}