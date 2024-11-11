#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int v,mini=10000;
  cin >> s;
  for(int i=0;i<s.size()-2;i++){
  v= abs(753-((s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0')));
  if(mini>v){
    mini=v;
  }
  }
  cout << mini << endl;
}