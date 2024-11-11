#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  string si, nc="Three";
  cin>>n;
  for(i=0;i<n;i++){
    cin>>si;
    if(si=="Y")nc="Four";
  }
  cout<<nc;
}