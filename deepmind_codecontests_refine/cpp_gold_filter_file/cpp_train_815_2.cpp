#include<iostream>
using namespace std;
long long a=2,n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a*=2;
		a+=2;
	}
	cout<<a<<endl;
}