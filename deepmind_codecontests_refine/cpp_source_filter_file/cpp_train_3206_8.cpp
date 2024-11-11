#include<iostream>
using namespace std;
int main(){
	long long a,b,c;
	cin>>a>>b>>c;
	if(c<=a){
		cout<<a-c<<' '<<b;
		return 0;
	}
	cout<<"0 "<<max(0,b-(c-a));
	return 0;
}