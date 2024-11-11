#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int x=0;
  for (int i=0 ; i<N ;i++){
    if (i+1==3*5*7 || i+1==3*3*3*5 || i+1==3*3*3*7 || i+1==3*5*11 || i+1==3*5*13 ||)
      x++;
  }
  
  cout << x << endl;
}