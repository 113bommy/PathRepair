#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;

int main() {
  int a,b,x,y;
  cin>>a>>b>>x>>y;
  x-=a;
  y-=b;
  rep(i,x) cout<<"R";
  rep(i,y) cout<<"U";
  rep(i,x) cout<<"L";
  rep(i,y+1) cout<<"D";
  rep(i,x+1) cout<<"R";
  rep(i,y+1) cout<<"U";
  cout<<"LU";
  rep(i,x+1) cout<<"L";
  rep(i,y+1) cout<<"D";
  cout<<"R";
  
}
