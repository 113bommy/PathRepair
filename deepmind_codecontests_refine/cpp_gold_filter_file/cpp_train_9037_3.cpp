#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n,c=0;
  cin>>n;
  ll a[n];
  cin>>a[0];
  if(a[0]!=0){
    cout<<-1;
    return 0;
  }
  for(int i=1;i<n;i++){
    cin>>a[i];
    if(a[i-1]+1==a[i]){
      c++;
    }else if(a[i-1]+1>a[i]){
      c+=a[i];
    }else{
      cout<<-1;
      return 0;
    }
  }
  cout<<c;
}