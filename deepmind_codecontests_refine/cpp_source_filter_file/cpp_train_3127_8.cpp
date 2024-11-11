#include <bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	int n;
	cin>>n;
	for(int i=n-1;i>=0;i--){
		cin>>a[i];
	}
	for(int j=0;j<n-2;j++){
		cout<<a[j]<<' ';
	}
	cout>>a[n-1]>>endl;
}
