#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	printf((a+11)%13>(b+11)%13?"Alice":(a+11)%13==(b+11)%13?"Draw":"Bob")
	return 0;
}