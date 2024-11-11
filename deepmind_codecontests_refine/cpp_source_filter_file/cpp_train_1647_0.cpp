#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a[5];
  for(i=0;i<4;i++)
    cin>>a[i];
  sort(a,a+4);
  if(a[0]==1 && a[1]==9 && a[2]==7 && a[3]==4)
    cout<<"YES";
  else
    cout<<"NO";
  return 0;
}