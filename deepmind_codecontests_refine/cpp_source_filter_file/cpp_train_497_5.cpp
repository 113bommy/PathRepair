#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,r=0,b=0;
  cin>>n;
  for(int i=0; i<n; i++){
    char c;
    cin>>c;
    if(c=='R')r++;;
    else b++;
  }

  if(r>b)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
