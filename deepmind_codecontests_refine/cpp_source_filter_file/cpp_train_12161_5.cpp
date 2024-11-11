#include <iostream>
#deine rep(i,n) for(int i=0; i<n; i++)
using namespace std;
int main(void){
  int n,m,c;cin>>n>>m>>c;
  int b[m],a[n][m];
  int cnt=0;
  rep(i,m)cin>>b[i];
  rep(i,n){
    int sol=0;
    rep(j,m){
      cin>>a[i][j];
      sol+=a[i][j]*b[j];
    }
    if(sol+c>0)cnt++;
  }
  cout<<cnt<<endl;
}