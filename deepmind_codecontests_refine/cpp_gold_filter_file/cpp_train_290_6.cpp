#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		m+=x-1;
	}
	cout<<m;
}