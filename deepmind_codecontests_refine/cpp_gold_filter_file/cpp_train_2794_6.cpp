#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,x;
  cin>>x>>a>>b;
  if(abs(x-a) > abs(x-b)) cout<<'B'<<endl;
  else cout<<'A'<<endl;
  return 0;
}