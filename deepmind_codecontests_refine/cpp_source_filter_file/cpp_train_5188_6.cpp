#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x  ;
  string ans = "Three"; 
  while(x>0){
    string s;
    cin >> s;
  if (s=='Y')
    ans ="Four";
    x--;
  }
  cout <<ans ;
}
