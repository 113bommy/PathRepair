#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  int n;
  cin>>n;
  ll ara[n+5];
  ll sum=0;
  for(int i=0;i<n;i++)cin>>ara[i],sum+=ara[i];
  ll cur=0;
  ll mn=12345678901234567;
  for(int i=0;i<n-1;i++)
  {
    cur+=ara[i];
    ll left=sum-cur;
    mn=min(mn,abs(cur-left);
  }
  cout<<mn<<endl;
}