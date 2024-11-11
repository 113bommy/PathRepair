#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
  int h,w;
  cin >> h >> w;
  string s;
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      cin >> s;
      if(s=='snuke') {
        cout << (char)('A'+j) << i+1 << endl;
      }
    }
  }
}