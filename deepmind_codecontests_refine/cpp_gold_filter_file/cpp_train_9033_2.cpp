#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<long> h(n);
  for(int i=0;i<n;i++) cin>>h[i];
  sort(h.begin(),h.end());
  long count=0;
  if(n>k){
    for(int i=0;i<n-k;i++)
    count+=h[i];
  }
  cout<<count<<endl;
}
