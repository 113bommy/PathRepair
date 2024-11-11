#include <bits/stdc++.h>
using namespace std;
int main(){
	long long x,k,d;
	cin>>x>>k>>d;
	x=abs(x);
	if(x/d>=k){
		cout<<x-d*k<<endl;
		return 0;
	}
	long long kai=x/d;
	if((k-kai)%2==0)cout<<x-d*kai<<endl;
	else cout<<abs(x-d*kai-d)<<endl;
}