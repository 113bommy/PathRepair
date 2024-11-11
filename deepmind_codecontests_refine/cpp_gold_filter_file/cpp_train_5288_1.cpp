#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll n,k,r,s,p,sum=0;
  string t;
  cin>>n>>k>>r>>s>>p>>t;
  for(int i=0; i<t.size(); i++){
    if(i>=k && t[i]==t[i-k]) t[i] = '0';
    if(t[i]=='r') sum += p;
    if(t[i]=='s') sum += r;
    if(t[i]=='p') sum += s;
  }
  cout<<sum;
}