#include<bits/stdc++.h>￼
using namespace std;
int main(){
  int a,b,c,d=0;
  cin >> a;
  c=a;
  while(a>0){
    b=a%10;
    d+=b;
    a/=10;
  }
  if(c%d==0)cout << "Yes";
  else cout << "No";
}
