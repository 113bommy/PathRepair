#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  
  char a;
  int b;
  for(int i=0; i<=h*w; i++) {
    string s;
    cin >> s;
    if(s=="snuke") {
      a = i%w+'A';
      b = i/w+1;
      break;
    }
  }
  cout << a << b << endl;
  return 0;
}
