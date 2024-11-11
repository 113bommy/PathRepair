#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  
  char a;
  int b;
  for(int i=0; i<h*w; i++) {
    string s;
    cin >> s;
    if(s=="snuke") {
      a = i%10+'A';
      b = i/10+1;
      break;
    }
  }
  cout << a << b << endl;
  return 0;
}