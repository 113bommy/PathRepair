#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt;
  int n;
  cin>>n;
  int s[n];
  for(i=0;i<n;i++)cin>>s[i];
  int sum=0;
  for(i=0;i<n;i++)sum+=s[i];
  if(sum%10!=0){
    cout<<sum;
    return 0;
  }
  int mi=INT_MAX;
  for(i=0;i<n;i++){
    if(s[i]%10!=0){
      mi=min(mi,s[i]);
    }
  }
  if(mi==INT_MAX)cout<<0;
  else cout<<sum-mi;
}