#include <iostream>
using namespace std;
int main(){
  string s;cin>>s;
  int mn = 0;
  int mx = s.size()-1;
  int ans = 0;
  while(mn < mx){
    if(s[mn] == s[mx]){
      mn++;mx--;
    }else if(s[mn] == 'x'){
      mn++;
      ans++;
    }else if(s[mx] == 'x'){
      mx--;
      ans++;
    }else{
      cout << -1 << endl;
      return 0;
  }
  cout << ans << endl;
}