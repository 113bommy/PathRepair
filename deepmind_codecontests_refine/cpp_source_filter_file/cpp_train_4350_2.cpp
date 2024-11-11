#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N;
  cin>>N;
  
  string ans="";
  while(N){
    N-=1;
    a.push_back('a'+N%26);
    N/=26;
  }
  reverse(ans.begin(),ans.end());
  cout<<ans<<endl;
}