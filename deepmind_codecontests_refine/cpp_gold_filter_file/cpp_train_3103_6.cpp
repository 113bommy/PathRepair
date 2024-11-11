#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)

int main(){
  int n,mi=10000,s1,s2;cin>>n;
  vector<int> w(n,0);
  REP(i,n) cin>>w.at(i);
  REP(i,n-1){
    s1=s2=0;
    REP(j,n){
      j<=i?s1+=w.at(j):s2+=w.at(j);
    }
    mi=min(mi,abs(s1-s2));
  }
  cout<<mi;
}