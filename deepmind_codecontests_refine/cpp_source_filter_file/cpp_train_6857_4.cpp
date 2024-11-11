#include<iostream>
using namespace std;

int main()
{
int x;
while(cin>>d)
{
y=0;
for(int i=1; i*d<600; i++)
{
 y+=d*(d*i)*(d*i);
}
cout<<y<<endl;
}
return 0;
}