#include<bits/stdc++.h>
using namespace std;
#define LL long long
char s[20];
map<ll,int>mp;
int main(){
	int n;scanf("%d",&n);
	LL ans=0;
	for(int i=0;i<n;i++){
		scanf("%s",s);
		sort(s,s+10);ll x=0;
		for(int j=0;s[j];j++){
			x=x*26+s[j]-'a';
		}
		ans+=mp[x];
		mp[x]++;
	}
	printf("%lld\n",ans);
	return 0;
}