#include<iostream>
using namespace std;
int main()
{
  int l,r,d,c=0;
  cin>>l>>r>>d;
  for( ; l<=r; l++)
  {
    if(l%d==0)
      c++;
  }
  cout<<c;
  
}
