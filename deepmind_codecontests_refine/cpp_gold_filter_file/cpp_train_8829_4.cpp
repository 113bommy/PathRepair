#include<bits/stdc++.h>
using namespace std;
int main(){
  long n,s=0;
  vector<int> v;
  cin>>n;
  v.resize(n);
  for(int i=0;i<n;i++){cin>>v[i];v[i]-=i+1;}
  sort(v.begin(),v.end());
  for(int i=0;i<n;i++)s+=abs(v[i]-v[n/2]);
  cout<<s<<endl;
  return 0;
}
