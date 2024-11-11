#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000010
char s[MAXN];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int a,b,c,d,n,i,j,k=0;
	cin>>n>>a>>b>>c>>d;
	for(i=1;i<=n;i++) cin>>s[i];
	for(i=a+1;i<c;i++)
		if(s[i]=='#' && s[i+1]=='#') { cout<<"No"<<endl; return 0; }
	for(i=b+1;i<d;i++)
		if(s[i]=='#' && s[i+1]=='#') { cout<<"No"<<endl; return 0; }
	for(i=b-1 ; i<d-1 ; i++)
		if((s[i]=='.' && s[i+1]=='.' && s[i+2]=='.') && i-1!=d) k=1;
	if(d>c) k=1;
	if(k==1) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}