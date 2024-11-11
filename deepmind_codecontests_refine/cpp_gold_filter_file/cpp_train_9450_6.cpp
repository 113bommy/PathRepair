#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  long long k;
  cin>>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  
  vector<int> s;
  vector<int> ord(n+1,-1);
  int c=1,l=0;
  int v=1;
  while(ord[v]==-1){
    ord[v]=s.size();
    s.push_back(v);
    v=a[v-1];
  }
  c=s.size()-ord[v];
  l=ord[v];
  if(l>=k){
    cout<<s[k]<<endl;
  }else{
    k-=l;
    k%=c;
    cout<<s[l+k]<<endl;
  }
  return 0;
}
