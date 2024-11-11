#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  string s; cin>>s;
  long long ans=1;
  vecto<long long> num(26,1);
  for(int i=0;i<n;i++){
    num[s[i]-'a']++;
  }for(int i=0;i<26;i++){
    ans*=num[i];
    ans%=1000000007;
  }
  cout<<ans-1<<endl;
}