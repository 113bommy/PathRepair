#include <bits/stdc++.h>
using namespace std;
int main(){
  char c;
  int a=0
  for(int i=0;i<3;i++){
    cin>>c;
    if(c=='o')
      a++;
  }
  cout<<700+a*100;
}