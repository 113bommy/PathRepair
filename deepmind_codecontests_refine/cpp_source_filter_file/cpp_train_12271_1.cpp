#include<bits/stdc++.h>
using namespace std;

int sq(int x){return x*x;}
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<(sq(max([a,b,c]))*2==sq(a)+sq(b)+sq(c) ? "YES" :"NO")<<endl;
  }
  return 0;
}