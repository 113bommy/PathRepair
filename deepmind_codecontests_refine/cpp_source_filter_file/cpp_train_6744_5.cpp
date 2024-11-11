#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,t;cin>>n;
  vector <int> cnt(n+1,0);
  for(int i=0;i<n;i++){
    cin>t;
    cnt[t]++;
  }
  for(int i=0;i<n;i++)cout<<cnt[i]<<endl;
}