#include <bits/stdc++.h>
using namespace std;

int main() {

  string T;
  cin >> T;
  
  for( char c : T){
    if(c == "?"){
      c = "D";
    }
    cout << c;
  }
    cout << endl;
}