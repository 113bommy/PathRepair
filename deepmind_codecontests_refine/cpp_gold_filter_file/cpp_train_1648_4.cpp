#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin >> s >> t;
  bool f=0;
  for(int i=0;i<s.size();i++){
    if(s==t){
      f=1;
      break;
    }
    s=s.back()+s.substr(0,s.size()-1);
  }
  if(f)cout << "Yes";
  else cout << "No";
}
