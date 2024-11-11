#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
int main(){
  int n;
  char str[10],com[13];
  map<string,bool> mp;
  cin >> n;
  rep(i,n){
    cin >> com >> str;
    if(com[0] == 'i') {mp[str] = true;
    //cout << string(str) << endl;}
    else {
      if(mp[string(str)]) cout << "yes" << endl;
      else cout << "no" << endl;
    }
  }
  return 0;
}
