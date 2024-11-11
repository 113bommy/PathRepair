#include <bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin >> s;
  int ans;
  t=s;
  for (int i=0;i<t.size()/2;i++){
    s=s.substr(0,s.size()-2);
    if(s.substr(0,s.size()/2)==s.substr(s.size()/2,s.size()/2)){
      break;
    }
  }
  cout << s.size() << endl;
}