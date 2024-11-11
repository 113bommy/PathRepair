#include<iostream>
   
using std::cin;
using std::cout;
using std::endl;
   
int main()
{
int x,y;
   
while(cin>>x>>y&&!(x==0&&y==0))
{
if(x>y)std::swap(x,y);
cout<<x<<" "<<y<<endl;
}
return 0;
}