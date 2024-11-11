#include<bits/stdc++.h>
using namespace std;

int main(){
  int X;
  cin >> X;
  for(int i = -100000; i < 500000; i++){
    for(int j = -1000000 j < i; j++){
      if((i*i*i*i*i - j*j*j*j*j) == X){
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
}
