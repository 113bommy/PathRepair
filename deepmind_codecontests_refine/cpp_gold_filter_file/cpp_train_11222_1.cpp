#include<iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int m=0,a=0,c=0,x=0;
	cin >>m;
	for(int i=1;i<n;i++)
	{
		cin>>a;
		if(a<=m)
			c++;
		else 
		{
			x=max(x,c);
			c=0;
		}
		m=a;
	}
	x=max(x,c);
	cout<<x<<endl;
	return 0;
}
