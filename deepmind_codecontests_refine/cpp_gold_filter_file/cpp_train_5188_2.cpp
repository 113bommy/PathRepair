#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  string p,c="Three";
  cin>>n>>p;
  for(int i=0;i<n;i++){
    if(p=="Y")
      c="Four";
    cin>>p;
  }
  cout<<c;
}
