#include <bits/stdc++.h>
using namespace std;

int main() {

  int a,b,i,c=0,e,f,g;
  cin>>a>>b;
  for(i=a;i<=b;i++){
    e=i%100;
    f=e%10;
    g=e/10;
  if(i/1000==(g+f*10))
    c++;
  }
  cout<<c;
}
