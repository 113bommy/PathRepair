#include <iostream>
using namespace std;
int main()
{
  int a;
  cin>>a;
  
  for(int i=1;i<10;++i)
  {
    if(a/i<10 && a%i==0)
    {
cout<<"Yes";
      return 0;
  }
  }  
   cout<<"No";
    return 0;
  
}