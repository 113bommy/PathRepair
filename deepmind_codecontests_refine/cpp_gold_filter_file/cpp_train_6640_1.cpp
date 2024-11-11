#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,a;cin>>n;
	while(n--){
		cin>>a;
		if(a%2==0&&a%3!=0&&a%5!=0){cout<<"DENIED";return 0;}
	}
	cout<<"APPROVED";
	return 0;
}