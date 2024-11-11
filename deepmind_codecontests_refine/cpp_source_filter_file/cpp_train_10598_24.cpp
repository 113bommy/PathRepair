#include <bits/stdc++.h>
using namespace std;

int main(){
  int r,d,a,i;
  cin>>r>>d>>a;
  for(i=0;i<10;i++){
    a=a*r-d;
    cout<<a;
  }
}