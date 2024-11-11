#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(n);i++)
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}
int n,ok=-1;
string s;
string ans[4]={"SS","SW","WS","WW"};
signed main(){
    cin>>n>>s;
    rep(i,4){
        for(int j=1;j<n;j++){
            if((s[j]=='o')^(ans[i][j-1]==ans[i][j]))ans[i]+='W';
            else ans[i]+='S';
        }
        if(ans[i][0]==ans[i][n]&&((s[0]=='o')^(ans[i][0]=='S')^(ans[i][1]==ans[i][n-1])))ok=i;
    }
    if(ok==-1)cout<<-1<<endl;
    else cout<<ans[ok].substr(0,n)<<endl;
	return 0;
}
