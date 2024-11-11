
#include<bits/stdc++.h>
using namespace std;


int main(){
	
	int n,k;
	cin>>n>>k;
	int ans = 0;
	int h;
	for(int i =0;i<n;i++){
		
		cin>>h;
		if(h>= k)
			ans++;
	}
	cout<<ans;
}