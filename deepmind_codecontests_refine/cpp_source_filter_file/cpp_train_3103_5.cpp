#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin >> n;
  int k[n+1];
  k[0]=0;
  rep(i,n){
    int a;
    cin >> a;
    k[i+1]=k[i]+a;
  }
  int mi=100000000;
  rep(i,n){
    mi=min(mi,abs(k[i+1]-(k[n]-k[i+1])))
  }
  cout << mi << endl;
}  
