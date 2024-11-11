#include <bits/stdc++.h>
using namespace std;
int main(){
   int a,b,c;
  cin>>a>>b>>c;
  for(int i=a;i<=min(a+c-1,b);i++) cout<<i<<endl;
  for(int i=max(b-c+1,a+c);i<=b;i++) cout<<i<<endl;
}