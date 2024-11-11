#include<bits/stdc++.h>
using namespace std;
int f[100005],p[100005],ans[100005],fp[100005];string s;
inline dfs(int i){
	if(fp[i])return p[i];
	fp[i]=1;
	if(f[i])return p[i]=i;
	if(s[i]=='L'){
		return p[i]=dfs(i-1);
	}else return p[i]=dfs(i+1);
}
int main(){
	cin>>s;
	for(int i=0;i<s.size()-1;i++){
		if(s[i]=='R'&&s[i+1]=='L'){
			f[i]=1;
		}
	}
	for(int i=0;i<s.size();i++){
		dfs(i);
		if(abs(p[i]-i)%2==0)ans[p[i]]++;else ans[p[i]+1]++;
	}
	for(int i=0;i<s.size();i++)cout<<ans[i]<<' ';
	return 0;
}