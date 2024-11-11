#include<iostream>
using namespace std;
int main(){
	int n=0;
	cin>>n;
	int a,b,c;
	int x,y,z;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
		if(a*a==b*b+c*c||b*b=a*a+c*c||c*c=a*a+b*b)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}