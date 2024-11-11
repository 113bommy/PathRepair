#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y;
    cin>>x>>y;
  cout<<max({x+y,x-y,x*y})<<endl;
  return 0;
}
