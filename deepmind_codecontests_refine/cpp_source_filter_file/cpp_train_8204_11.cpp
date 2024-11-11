#include <iostream>
#include <string>
using namespace std;
int main() {
int n;
string s;
cin>>n;
cin>>s;
int r = 0;
for(int i = 1; i < n; i++) {
int k = 0;
for(char c = 'a'; a <= 'z'; c++) {
  bool f = false, t = false; 
  for(int j = 0; j < i; j++) {
  if( s[j] == c) f = true;
  }
  for(int j = i; j < n; j++) {
  if(s[j] == c) t = true;
  }
  if(f && t) k++;
}
  if(r < k) r = k;
}
  
cout<<r<<endl;
return 0;
}