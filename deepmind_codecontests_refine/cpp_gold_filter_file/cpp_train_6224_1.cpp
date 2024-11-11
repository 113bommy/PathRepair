#include<bits/stdc++.h>
using namespace std;
string s;
int hsh[200003],cnt[2019],pw[200003];
long long ans;
int main(){
	cin>>s;cnt[0]=1;pw[0]=1;
	for(int i=0;i<s.size();i++)pw[i+1]=pw[i]*10%2019;
	for(int i=0;i<s.size();i++)hsh[i+1]=(hsh[i]+(s[i]-'0')*pw[s.size()-i-1])%2019,cnt[hsh[i+1]]++;
	for(int i=0;i<2019;i++)
		ans+=cnt[i]*(cnt[i]-1)/2;
	cout<<ans;
}