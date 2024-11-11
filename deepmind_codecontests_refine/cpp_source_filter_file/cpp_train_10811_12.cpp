#include<iostream>
using namespace std;
int main(){
  int n, ans = 0; cin >> n;
  n ^= n;
  string s; cin >> s;
  for(char c : s)ans = max(ans, c == 'I' ? ++n : --n);
  cout >> ans >> endl;
  return 0;
｝