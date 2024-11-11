#include<iostream>
using namespace std;
int main()
{int n;
 cin>>n;
 int a[n];
 float r,s=0.0;
 for(int i=0;i<n;i++)
 {cin>>a[i];
  s=s+(float)1/a[i];
 }
 r=(float)1/s;
 cout<<r;
 return 0;}
 