#include<bits/stdc++.h>
using namespace std;
int i,n,a[100000];
int main(){
  for(cin>>n;i<n;i++)cin>>a[i];
  sort(a,a+n);
  cout<<a[n/2]-a[n/2-1];
}