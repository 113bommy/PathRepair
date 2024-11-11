#include<bits/stdc++>
using namespace std;

int main(){
	int n,k;cin>>n>>k;
	vector<int> h(n);
	for(auto&& u:h)cin>>u;
	sort(begin(h),end(h));
	int mn=1e9;
	for(int i=0;i+k-1<n;i++)mn=min(mn,h[i+k-1]-h[i]);
	cout<<mn<<endl;	
}