#include<bits/stdc++.h>
using namespace std;
int main(){
  int r,d,x1,i=10;
  cin>>r>>d>>x1;
  while(i--){
    x1=r*x1-d;
    cout<<x1<<endl;
  }
  return 0;
}
