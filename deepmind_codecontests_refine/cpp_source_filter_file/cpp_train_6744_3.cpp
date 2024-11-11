#include<bits/stdc++.h>
using namespace std;
int f[200005];
int main() {
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int k;
		cin>>k;
		f[k]++;
	}
	for(int i=1;i<=n;i++){
		cout<<f[k]<<endl;
	}

	return 0;
}
