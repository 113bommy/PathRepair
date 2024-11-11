#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;cin>>n>>k;
	if(k==1 || k==2*n-1){
		cout<<"No"<<endl;
		return 0;
	}
	else{
	cout<<"Yes"<<endl;
	if(n==k){
		for(int i=1;i<=2*n-1;i++){
			cout<<i<<endl;
		}
	}
	else if (k<n){
		for(int i=n+k-2;i>=k-1;i--){
		cout<<i<<endl;}
		for(int i=n+k-1;i<=2*n-1;i++){
		cout<<i<<endl;}
		for(int i=1;i<k-1;i++){
		cout<<i<<endl;}
	}
	else{
		for(int i=k-n+2;i<=k+1;i++){
			cout<<i<<endl;
		}
		for(int i=k-n+1;i>=1;i--){
			cout<<i<<endl;
		}
		for(int i=k+2;i<=2*n-1;i++){
			cout<<i<<endl;
		}

	}

}