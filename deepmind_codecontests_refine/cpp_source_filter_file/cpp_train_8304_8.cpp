#include <bits/stdc++.h>
using namespace std;

signed main(){
  int h,n;cin>>h>>n;
  while(n--){
    int a;cin>>a;
    h-=a;
  }
  cpit<<(h>0?"No":"Yes")<<endl;
}