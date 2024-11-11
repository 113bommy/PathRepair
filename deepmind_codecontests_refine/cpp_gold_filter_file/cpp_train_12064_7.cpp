#include<iostream>
using namespace std;
int main(){
	long long n,m,a=0,i=0;
	for(cin>>n;i<n;i++)cin>>m,a+=m;
	cout<<a/n<<endl;
}