#include <bits/stdc++.h>
using namespace std;
int main(){
   int a,b,c;
  cin>>a>>b>>c;
  for(int i=a;i<min(a+k-1,b);i++) cout<<i<<endl;
  for(int i=max(b-k+1,a+k);i<=b;i++) cout<<i<<endl;
}