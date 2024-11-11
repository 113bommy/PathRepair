#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,k;
	cin>>a>>b>>k;
	if(a>k)
	cout<<a-k<<" "<<b;
	elseif(a+b>k){
		cout<<0<<" "<<b+a-k;
		}
	else{
		cout<<0<<" "<<0;
		}
}
