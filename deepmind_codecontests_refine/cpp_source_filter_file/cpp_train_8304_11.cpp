#include <iostream>
using namespace std;
int h, a;
long long sum;
int main()
{
	cin>>h>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		sum+=x;
	}
	if (sum<h)	cout<<"No";
	else cout<<"Yes";
	return 0;
}