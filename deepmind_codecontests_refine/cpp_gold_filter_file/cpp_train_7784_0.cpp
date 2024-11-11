#include<iostream>
  
using namespace std;
int main() 
{
  int n,m;
  cin>>n>>m;
  int a=1,b=n;
  for(int i=0;i<m;i++)
  {
    cout<<a<<' '<<b<<'\n';
    a++;
    b--;
    int d1=b-a,d2=n-d1;
    if(d1==d2||d1+2==d2) b--;
  }
}