#include <bits/stdc++.h>
using namespace std;

int main(){
  string O, E;
  cin>>O>>E;
  int Z=O.size()+E.size();
  for(int i=0; i<Z; i++){
    if(i%2==0) cout<<O.at(i/2);
    else cout<<E.at((i-1)/2);
  }
}
