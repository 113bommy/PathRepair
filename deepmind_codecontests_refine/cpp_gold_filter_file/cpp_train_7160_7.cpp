#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
  string t=s;
  reverse(t.begin(),t.end());
  return s==t;
}

int main() {
  string s;
  cin >> s;
  bool ans=true;
  if(!isPalindrome(s)) ans=false;
  if(!isPalindrome(s.substr(0,s.size()/2))) ans=false;
  puts(ans?"Yes":"No");
  return 0;
}
  
