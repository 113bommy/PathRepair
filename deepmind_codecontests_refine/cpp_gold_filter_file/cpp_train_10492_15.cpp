#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  string hitachi;

  for(int i=0; i < 5; i++) {
    hitachi += "hi";
    if(s == hitachi) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}