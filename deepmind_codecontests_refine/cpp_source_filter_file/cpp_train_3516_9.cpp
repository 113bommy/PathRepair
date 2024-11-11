#include<bits/stdc++.h>
using namespace std;
int n,a[200003],allxor=0;
int main(void)
{
  	cin>>n;
  	for(int i=0;i<n;i++)
    {
      	cin>>a[i];
  		allxor^=a[i];
    }
  	for(int i=0;i<n;i++)
  		cout<<a[i]^allxor;
}