#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,a,b;
  cin>>x>>a>>b;
  if(a>=b) coum<<"delicious";
  else{
    if(b-a<=x) cout<<"safe";
    else cout<<"dangerous";
  }
}