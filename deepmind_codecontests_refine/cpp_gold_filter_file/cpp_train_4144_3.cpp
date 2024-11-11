#include<iostream>
using namespace std;
int main()
{
	int a,b;
	
	cin>>a>>b;
	
	int i=0, j=1;
	while(j < b)
	{
	j--;
	j=j+a;
	i++;
	}
	cout<<i;
}