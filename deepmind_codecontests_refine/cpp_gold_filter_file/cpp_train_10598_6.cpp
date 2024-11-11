#include<iostream>
using namespace std;
int main()
{
  int r,x,d;
  cin>>r>>d>>x;
  for(int i=0;i<10;i++)
  {
    	x=(r*x)-d;
    	cout<<x<<"\n";
  }
}