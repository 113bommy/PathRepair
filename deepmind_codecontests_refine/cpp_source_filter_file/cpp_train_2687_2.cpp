#include <bits/stdc++.h>
using namespace std;
int main(void){
  string s;
  int r=0;
  int t=0;
  cin >> s;
  for(auto x:s){
    if(x=='A'||x=='T'||x=='G'||x=='C'){
      t++;
    }
    else{
      if(t==0)continue;
      else if(t>r)r=t;
      t=0;
    }
  }
  cout<<r>t?r:t<<endl;
  return 0;
}