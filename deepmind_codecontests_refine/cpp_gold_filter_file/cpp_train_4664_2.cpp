#include <bits/stdc++.h>
using namespace std;

int main(){
  int X,Y; cin >> X >> Y;
  cout << (X==1&&Y==1?400000:0)+100000*(max(4-X,0)+max(4-Y,0)) << endl;
}