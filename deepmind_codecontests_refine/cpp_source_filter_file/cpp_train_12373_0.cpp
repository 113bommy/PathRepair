#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)

int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n)cin>>s.at(i);
  rep(j,26){
    m = 100;
    rep(i,n)m = min(m, count(s.at(i).begin(),s.at(i).end(),(char)('a'+j)));
    rep(i,m)cout<<(char)('a'+j);
  }
  cout<<endl;
  return 0;
}