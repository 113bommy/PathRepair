#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<tuple<string,int,int>>a;
  for(int i=1;i<=n;i++){
    string s;
    int p;
    cin>>s>>p;
    p=-p;
    a.push_back(tie(s,p,i))
  }
  sort(a.begin(),a.end());
    rep(i,n)
  cout << get<2>(a[i]) <<endl;
}