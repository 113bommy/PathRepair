#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n,c=0,a;
  cin>>n;
  for(ll i=0;i<n;i++){
    cin>>a;
    c+=a-1;
  }
  cout<<c;
}