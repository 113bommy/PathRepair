#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int main(){
	int n;cin>>n;
	for(inti=0;i<n;i++)cin>>arr[i];
	long long l=2,r=2;
	for(int i=n-1;i>=0&&l<=r;i--){
		long long x=(l+arr[i]-1)/arr[i],y=r/arr[i];
		l=x*arr[i],r=(y+1)*arr[i]-1;
	}
	if(l>r)cout<<"-1";else cout<<l<<" "<<r;
}
