#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	int x[n];
	for(int i=0;i<n;i++) cin>>x[i];
	
	int ans=1000000;
	for(int p=1;p<100;p++){
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=pow((x[i]-p),2)  //pow(x,n)xのn乗を計算
		}
		ans=min(ans,sum)
	}
	cout<<ans<<endl;
}