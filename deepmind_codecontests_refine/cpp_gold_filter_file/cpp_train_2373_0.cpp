#include <bits/stdc++.h>
using namespace std;

int main(){
  int X,b=0;
  cin >> X;
  for(int i=1;i<=X;++i){
    if(100*i<=X&&X<=105*i){
      b = 1;
    }
  }
  cout << b << endl;
}