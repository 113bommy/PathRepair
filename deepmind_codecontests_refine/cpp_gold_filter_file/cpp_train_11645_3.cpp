#include<iostream>
using namespace std;
int main(){
	long long a;
	long long n,b;
	cin>>n>>a>>b;
	if(n>1&&b>=a||n==1&&a==b){
		cout<<(n-2)*(b-a)+1;
		return 0;	
	}else{
		cout<<"0";
	}
	return 0;
}