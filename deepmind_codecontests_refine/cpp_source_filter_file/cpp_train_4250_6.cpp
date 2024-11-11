#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,c,d;
  cin>>a>>b>>c;
  d=max(a,b)+1
  while(c>0){
    d--;
    if(a%d==0 && b%d==0) c--;
  }
  cout<<d;
}