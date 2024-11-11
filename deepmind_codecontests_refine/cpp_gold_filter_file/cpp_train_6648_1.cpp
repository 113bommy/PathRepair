#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int n,k,m[26],a=0;
string s[10001];
priority_queue<int>q;
int main(){
	cin>>n>>k;
	rep(i,n){cin>>s[i];m[s[i][0]-'A']++;}
	rep(i,26)if(m[i])q.push(m[i]);
	while(q.size()>=k){
		rep(i,k){m[i]=q.top();q.pop();}
		rep(i,k)if(m[i]>1)q.push(m[i]-1);
		a++;
	}
	cout<<a<<endl;
	return 0;
}