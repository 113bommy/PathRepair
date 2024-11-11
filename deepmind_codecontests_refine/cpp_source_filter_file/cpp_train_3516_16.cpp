#include<iostream>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int a[n];
  int x = 0;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    x = x^a[i];
  }
  for(int i=0;i<n;i++)
  {
    int temp = x;
    ans = temp ^ a[i];
    cout<<ans<<endl;
  }
}