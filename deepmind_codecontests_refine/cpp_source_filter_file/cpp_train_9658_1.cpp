#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int res=0;
  for(int i=1;i<=n;i++)
  {
    int k;
    cin>>k
      if(k%2==1&&i%2==1)
        res++;
  }
  cout<<res;
  return 0;
}