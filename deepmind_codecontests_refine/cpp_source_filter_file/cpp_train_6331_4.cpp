#include <bits/stdc++.h>

using namespace std;
int n,p[12345];
signed main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>p[i];
	sort(p,p+n);
	
	for(int i=0;i<n-1;i++){
		a+=p[i];
	}
	a+=p[i]/2;
	cout<<a<<endl;
}
