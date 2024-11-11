#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<int>h(n);
	for(auto&& u:a)cin>>u;
	int ret=a[0];
	for(int i=0;i<n-1;i++){
		if(a[i+1]>a[i])ret+=a[i+1]-a[i];
	}
	cout<<ret<<endl;
}