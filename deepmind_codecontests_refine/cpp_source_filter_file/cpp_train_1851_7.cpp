#include <iostream>
using namespace std;
int main()
{
int a,b,x,y,s=0;
cin>>a>>b;
for(int i=0;i<a;i++){
cin>>x>>y;
if(x*x+y*y<=b*b) s++
}
 cout<<s;
 return 0;
}