#include <bits/stdc++.h>
using namespace std;
 
 
int main(){
  int H, W;
  cin >> H >> W;
  for(int row=0; row<H; row++){
    for(int col=0; col<W; col++){
      string s;
      cin >> s;
      if(s=="snuke"){
        cout << char(col + 'A') << row + 1 << endl;
        return 0;
      }
    }
  }
  return 0;
}
