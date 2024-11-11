#include <iostream>
using namespace std;
int main()
{
	long long n,i,a[60];
	cin>>n;
	a[0]=2;
	for (i=1;i<=n;i++) a[i]=a[i-1]*2+2;
	cout<<a[n]<<endl;
	return 0;
}