#include <bits/stdc++.h>
using namespace std;
int main(){
  int H,W;
  cin >> H >> W;
  int C = 0;
  char c;
  for (int i = 0; i < H * W; i++){
    cin >> c;
    if (c == '#') C++;
  }
  cout << (C = H + W - 1 ? "Possible" : "Impossible");
}