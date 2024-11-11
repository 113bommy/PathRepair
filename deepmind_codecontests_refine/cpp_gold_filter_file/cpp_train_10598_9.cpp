#include <bits/stdc++.h>
using namespace std;
int main(){
  int r,d,a;
  cin>>r>>d>>a;
  for(int i=0;i<10;i++){
    a=a*r-d;
    cout<<a<<endl;
  }
}