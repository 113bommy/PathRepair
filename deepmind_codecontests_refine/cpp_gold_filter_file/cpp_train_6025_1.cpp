#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)

signed main(){
	int n,l;cin>>n>>l;
	vector<int>a(n);
	for(auto&& u:a)cin>>u;
	int tmp=-1;
	rep(i,n-1)if(a[i]+a[i+1]>=l){tmp=i;break;}
if(tmp==-1){
	cout<<"Impossible"<<endl;
}else{
	cout<<"Possible"<<endl;
	for(int i=0;i<tmp;i++)cout<<i+1<<endl;
	for(int i=n-2;i>tmp;i--)cout<<i+1<<endl;
	cout<<tmp+1<<endl; 
}

}
