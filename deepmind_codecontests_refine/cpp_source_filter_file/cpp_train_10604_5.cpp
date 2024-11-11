#include <bits/stdc++>
using namespace std;

int main(){
  string s;
  cin >> s;
  string t="CODEFESTIVAL2016";
  int res=0;
  for(int i=0;i<t.size();++i){
    if(s[i]!=t[i])res++;
  }
  cout<<res<<endl;
}