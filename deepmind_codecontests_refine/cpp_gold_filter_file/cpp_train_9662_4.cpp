#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<int>h(n);
	for(auto&& u:h)cin>>u;
	int ret=h[0];
	for(int i=0;i<n-1;i++){
		if(h[i+1]>h[i])ret+=h[i+1]-h[i];
	}
	cout<<ret<<endl;
}