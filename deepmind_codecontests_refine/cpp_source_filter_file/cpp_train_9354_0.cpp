#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int h,w;cin>>h>>w;
  rep(i,h)rep(j,w){
    string s;cin>>s;
    if(s=="snuke"){
      vout<<'A'+j<<i+1<<endl;
    }
  }
  return 0;
}