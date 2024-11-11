#include<vector>
#include<iostream>
#include<map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<deque>
#define ll long long
using namespace std;
#define BUF_SIZE 1048576
char _buf[BUF_SIZE],*_is=_buf,*_it=_buf;
inline char rdc(){
	if (_is==_it) _it=(_is=_buf)+fread(_buf,1,BUF_SIZE,stdin);
	return *_is++;
}
inline void rdi(int &x){
	int f=0;
	register char ch=rdc();
	while ((ch<'0' or ch>'9') and (ch^'-')) ch=rdc();
	if (ch=='-') f=1,ch=rdc();
	while (ch>='0' and ch<='9') x=(x<<3)+(x<<1)+(ch^'0'),ch=rdc();
	if(f) x=-x;
}
inline void rdi(ll &x){
	ll f=0;
	register char ch=rdc();
	while ((ch<'0' or ch>'9') and (ch^'-')) ch=rdc();
	if (ch=='-') f=1,ch=rdc();
	while (ch>='0' and ch<='9') x=(x<<3)+(x<<1)+(ch^'0'),ch=rdc();
	if(f) x=-x;
}
inline void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
inline void _write(int x){
	write(x);
	putchar(' ');
}
inline void print(int x){
	write(x);
	putchar('\n');
}
inline void write(ll x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
inline void _write(ll x){
	write(x);
	putchar(' ');
}
inline void print(ll x){
	write(x);
	putchar('\n');
}
#define int ll
int res,n,d;
int a[200005];
int dpl[200005],dpr[200005]; 
signed main(){
	rdi(n),rdi(d);
	int i,j;
	for(i=0;i<n;++i) rdi(a[i]),res+=a[i];
	res+=(n-1)*d;
	dpr[0]=a[0];
	for(i=1;i<n;++i) dpr[i]=min(a[i],dpr[i-1]+d);
	dpl[n-1]=a[n-1];
	for(i=n-2;~i;--i) dpl[i]=min(a[i],dpl[i+1]+d);
	for(i=1;i<n-1;++i) res+=min(dpl[i],dpr[i]);
	print(res);
	return 0;
}