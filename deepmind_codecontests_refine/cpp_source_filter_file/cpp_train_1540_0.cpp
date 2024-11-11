#include<iostream>
using namespace std;
int n,m,a[10009];

int main()
{
	cin >> n >> m;
	for(int i = 0;i<m;i++)cin >> a[i];
	for(int i = 0;i<m;i++)n -= a[i];
	cout << n>=0?n:-1;
	return 0;
}