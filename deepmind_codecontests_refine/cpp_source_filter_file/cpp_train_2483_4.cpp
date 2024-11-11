#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>N(n);
	for(int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;
		++N[a]
		++N[b]
	}
	for(int i=1;i<=n;++i){
		cout<<N[i]<<endl;
	}
}
		