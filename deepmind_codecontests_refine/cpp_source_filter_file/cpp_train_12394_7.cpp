#include <iostream>

int main()
{
using namespace std;

int x,y;

while(1)
{
cin>>x>>y;
count++;

if(x==0 && y==0)
break;

if(x>y)
cout<<y<<' '<<x<<endl;
else
cout<<x<<' '<<y<<endl;
}
return 0;
}