#include <bits/stdc++.h>
using namespace std;
const int N = 250001,M = 1e9 + 9,M1 = 1e9 + 7,b = 103,b1 = 11;
int cs[N],cs1[N],p[N],p1[N],n;
map<pair<int,int>,int>mp;
void add(int &a,int b){
	a+=b;
	if(a >= M)a-=M;
	if(a < 0)a+=M;
}
void add1(int &a,int b){
	a+=b;
	if(a >= M)a-=M1;
	if(a < 0)a+=M1;
}
int power(int base,int to){
	int ret = 1;
	while(to){
		if(to&1)ret = ret*1LL*base%M;
		to>>=1;
		base = base*1LL*base%M;
	}
	return ret;
}
int power(int base,int to){
	int ret = 1;
	while(to){
		if(to&1)ret = ret*1LL*base%M1;
		to>>=1;
		base = base*1LL*base%M1;
	}
	return ret;
}
int main(){
//	freopen("readin.txt","r",stdin);
	scanf("%d",&n);
	p[0] = p1[0] = 1;
	char c;
	int inv = power(b,M - 2),inv1 = power1(b1,M1 - 2);
	for(int i = 1;i <= n;i++){
		scanf(" %c",&c);
		cs[i] = cs[i - 1];
		p[i] = p[i - 1];
		cs1[i] = cs1[i - 1];
		p1[i] = p1[i - 1];
		if(c == '+')add(cs[i],p[i]),add1(cs1[i],p1[i]);
		else if(c == '-')add(cs[i],-p[i]),add1(cs1[i],-p1[i]);
		else if(c == '>')p[i] = p[i]*1LL*b%M,p1[i] = p1[i]*1LL*b1%M1;
		else if(c == '<')p[i] = p[i]*1LL*inv%M,p1[i] = p1[i]*1LL*inv1%M1;
	}
	long long ans = 0;
	for(int i = 0;i <= n;i++){
		ans+=mp[{cs[i],cs1[i]}];
		mp[{(cs[n]*1LL*p[i] + cs[i] + M)%M,(cs1[n]*1LL*p1[i] + cs1[i] + M1)%M1}]++;
	}
	cout << ans << endl;
}
