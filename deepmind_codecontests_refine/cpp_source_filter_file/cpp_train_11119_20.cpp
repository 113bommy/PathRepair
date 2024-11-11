#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b,c,d,e,k;cin>>a>>b>>c>>d>>e>>k;
  cout <<( max({a,b,c,d,e})-min({a,b,c,d,e})<=k  ? "Yay!":":(")<endl;
}