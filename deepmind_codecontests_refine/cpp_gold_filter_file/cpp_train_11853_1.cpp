#include<bits/stdc++.h>
using namespace std;
int main()
{
  int H,W;
  string a;
  cin>>H>>W;
  for(int i=0;i<W+2;i++)
  {
    cout<<'#';
  }
  cout<<endl;
  for(int j=0;j<H;j++)
  {
    cin>>a;
    cout<<'#'<<a<<'#'<<endl;
  }
  for(int k=0;k<W+2;k++)
  {
    cout<<'#';
  }
  cout<<endl;
}
