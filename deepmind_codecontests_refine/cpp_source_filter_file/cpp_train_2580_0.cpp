#include<bits/stdc++.h>
using namespace std;
int main()
{
  double w,h,n;
  cin>>w>>h>>n;
  cout<<ceil(n/max(w,h))<<endl;
