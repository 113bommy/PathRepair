#include<bits/stdc++.h>
using namespace std;
int main(){
  
  int n,sum=0,k; cin>>n>>k;
    int ar[n];
  
  for(int i=0;i<n;i++)
    cin>>ar[i];
  sort(ar,ar+n);
  for(int i=0;i<k;i++)
    sum+=ar[i];
  cout<<sum;
}
