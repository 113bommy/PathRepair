#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
  int i=0;
  for(a;a<=b;a++){
    if ((a/10000==a%10)&&(a/1000%10==a/10%10))
      i++;
  }
  cout<<i<<endl;
}
