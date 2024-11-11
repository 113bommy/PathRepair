#include <bits/stdc++.h>
using namespace std;

int main(){
  int n=0;
  for(int i=0; i<3; i++){
    char c; cin>>c;
    if(c=='o') n++;
  }
  cout<<700+n*100;
}