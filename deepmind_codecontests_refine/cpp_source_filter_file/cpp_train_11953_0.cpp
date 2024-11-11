#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  vector<string> abc(n);
  rep(i,3)cin>>abc[i];
  int result=0;
  rep(i,n){
    set<char>s;
    rep(j,3)s.insert(abc[j][i]);
    result+=(s.size()-1)
  }

  cout<<result;

  return 0;
}