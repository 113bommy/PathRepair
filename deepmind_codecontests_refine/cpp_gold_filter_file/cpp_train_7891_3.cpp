#include <bits/stdc++.h>
using namespace std;
int main(){
  long long s,mi=753;
  cin>>s;
  for(int i=0;i<8;i++){
    mi=min(mi,abs(s%1000-753));
    s/=10;
  }
  cout<<mi<<endl;
}