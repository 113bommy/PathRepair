#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int H,M,X,Y,K;
  cin >> H >> M >> X >> Y >> K;
  
  cout << ( (X-H)*60 - (M-Y)) - K << endl; 
