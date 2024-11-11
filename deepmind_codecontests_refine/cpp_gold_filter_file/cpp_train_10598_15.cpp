#include<bits/stdc++.h>
using namespace std;

int main(){
  int r,D,x;
  cin>>r>>D>>x;
  for(int i=0;i<10;i++){
    x=x*r-D;
    cout<<x<<endl;
  }
  return 0;
}