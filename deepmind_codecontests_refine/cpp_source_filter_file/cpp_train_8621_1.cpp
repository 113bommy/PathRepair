#include <bits/stdc++.h>
using namespace std;
const int N = 250001,long long M = (long double)1e18 + 31,b = 1e9 + 7;
long long cs[N],p[N],n;
map<long long,int>mp;
void add(long long &a,long long b){
	a+=b;
	if(a >= M)a-=M;
	if(a < 0)a+=M;
}
long long power(long long base,long long to){
	long long ret = 1;
	while(to){
		if(to&1)ret = (__int128)ret*base%M;
		to>>=1;
		base = (__int128)base*base%M;
	}
	return ret;
}
int main(){
//	freopen("readin.txt","r",stdin);
	scanf("%d",&n);
	p[0] = 1;
	char c;
	long long inv = power(b,M - 2);
	for(int i = 1;i <= n;i++){
		scanf(" %c",&c);
		cs[i] = cs[i - 1];
		p[i] = p[i - 1];
		if(c == '+')add(cs[i],p[i]);
		else if(c == '-')add(cs[i],-p[i]);
		else if(c == '>')p[i] = (__int128)p[i]*b%M;
		else if(c == '<')p[i] = (__int128)p[i]*inv%M;
	}
	long long ans = 0;
	for(int i = 0;i <= n;i++){
		ans+=mp[cs[i]];
		mp[((__int128)cs[n]*p[i]%M + cs[i] + M)%M]++;
	}
	cout << ans << endl;
}
