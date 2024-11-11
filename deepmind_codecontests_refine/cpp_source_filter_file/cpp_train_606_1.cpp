#include<iostream>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n;i++)
#define int64 long long
#define yokuwaruprime (10*10*10*10*10*10*10*10*10+7)
using namespace std;

int main(){
  int n,m
  cin>>n>>m;
  int64 x[n],y[m];
  rep(i,n){
    cin>>x[i];
  }
  rep(i,m){
    cin>>y[i];
  }
  int64 bigX=0,bigY=0;
  rep(i,n){
    bigX+=(2*i-n+1)*x[i];
    bigX%=yokuwaruprime;
  }
  rep(i,m){
    bigY+=(2*i-m+1)*y[i];
    bigY%=yokuwaruprime;
  }
  cout<<(bigX*bigY)%yokuwaruprime<<endl;
}