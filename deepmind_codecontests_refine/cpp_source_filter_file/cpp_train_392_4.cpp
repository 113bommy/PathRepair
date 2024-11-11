#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;++i){
    cin>>a[i];
    b[i]=a[i];
  }
  sort(a,a+n);
  int lar=a[n-1], slar=a[n-2];
  for(int i=0;i<n;++i){
  if(b[i]==lar) cout<<slar<<'\n';
    else cout<<lar<<'\n';
  }
}
