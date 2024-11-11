
#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long A,B,N;
	cin>>A>>B>>N;
	long long y=B-1;
	if (N<B)  y=N;
	cout<<((y%B)*A)/B; 
	return 0;
}
