#include <bits/stdc++.h>
using namespace std;

int main(){
  int lose = 0;
  char c;
  while(cin >> c){
    if(c == 'x') lose++;
  }
  cout << ((lose >= 8) ? : "NO" : "YES") << endl;
}