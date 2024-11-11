#include <cstdio>
#include <iostream>
#define rep(i,k,n) for(int i=k;i<(int)(n);i++)
int n;
using namespace std;
int main(){
  cin >> n;
  int mi = n;
  rep(i,0,n+1){
    int cc = 0;
    int t = i;
    while(t>0) cc+=t%6 , t/=6;
    t = n-i;
    while(t>0) cc+=t%9 , t/=9;
    if(mi>cc) mi=cc;
  }
  cout << mi << endl;
  return 0;
}
