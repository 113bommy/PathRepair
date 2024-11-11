#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,m,f[N],g[N],ans[N]; char s[N],t[N];
inline void write(int u){
	if(u>9) write(u/10); putchar(u%10+'0');
}
int main(){
	cin>>n; int a=1,b=1;
	for(int i=1;i<=n/2;i++) a=a*3;
	for(int i=n/2+1;i<=n;i++) b=b*3;
	for(int i=0;i<a*b;i++){
		f[i]=f[i/3]*3,g[i]=(g[i]+1)%(a*b);
		if(i%3==1) f[i]+=2; else if(i%3==2) f[i]++;
	}
	scanf("%s",s+1),m=strlen(s+1);
	for(int i=0;i<a;i++){
		int u=i; int len=0;
		for(int z=1;z<=m;z++)
			if(s[z]=='S'){
				u=f[u];
				if(t[len]=='S') len--; else t[++len]='S';
			}
			else if(s[z]=='R'){
				if(u+1==a) t[++len]='R',u=0;
				else u++;
			}
		int v=u;
		for(int x=0;x<b;x++){
			int u=x;
			for(int z=1;z<=len;z++)
			if(t[z]=='S') u=f[u];
			else if(t[z]=='R'){
				if(u+1==b) u=0;
				else u++;
			}
			ans[i+x*a]=u*a+v;
		}
	}
	for(int i=0;i<a*b;i++) write(ans[i]),putchar(' ');
}