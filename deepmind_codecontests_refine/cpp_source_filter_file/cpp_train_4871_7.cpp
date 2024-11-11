include <bits/stdc++.h>
using namespace std; 
int main() {
  long int H, W;
  cin >> H >> W;
  if ( H == 1 || W == 1 ) {
  cout << 1 << endl;
  }
  else {cout << (h*w+1)/2 << endl;
  }
}