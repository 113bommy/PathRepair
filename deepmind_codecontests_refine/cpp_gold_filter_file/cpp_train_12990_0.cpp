#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long a,b,c;
	cin>>a>>b>>c;
	if(c>=b) c=b-1;
	cout<<floor(a*c/b)-a*floor(c/b)<<endl;
}