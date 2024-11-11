#include<iostream>
using namespace std;
int in(){int a;cin>>a;return a;}
int a[100001],b[100001],ans,ak=1e9+7,ac=ak;
int main(){
	int n=in(),m=in(),k=in();
	for(int i=1;i<=n;i++)a[i]=in(),ac=min(a[i],ac);
	for(int i=1;i<=m;i++)b[i]=in(),ak=min(b[i],ak);
	ans=ak+ac;
	while(k--)ans=min(ans,a[in()]+b[in()]-in());
	return cout<<ans<<endl,0;
}