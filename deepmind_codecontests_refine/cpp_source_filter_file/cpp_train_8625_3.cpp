#include <bits/sstdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int ans = 0;
  for(int i=0;i<s.size();++i){
    if(i%2 == 0 && s[i] == 'p') --ans;
    if(i%2 == 1 && s[i] == 'g') ++ans;
  }
  cout << ans << endl;
  return 0;
}