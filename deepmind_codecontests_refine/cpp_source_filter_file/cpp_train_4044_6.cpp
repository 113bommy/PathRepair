#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n,l[100];
  cin>>n;
  l[0]==2,l[1]==1;
  
  for(int i=2;i<=86;i++){
    l[i]=l[i-1]+l[i-2];
  }
  cout<<l.at(n)<<endl;
}
