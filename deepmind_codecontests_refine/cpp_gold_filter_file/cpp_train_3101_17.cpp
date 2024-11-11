#include<iostream>
using namespace std;
int main()
{
  long long a,b,c;
  cin>>a>>b>>c;
  if((c-b-a)>0&&4*a*b<((c-b-a)*(c-b-a))) cout<<"Yes";
  else cout<<"No";
return 0;
}