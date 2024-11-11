#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  string w="AKIHABARA";
  for(int mask=0;mask<(1<<9);mask++;){
    bool t=true;
    string p="";
    for(int i=0;i<9;i++){
      if(mask &(1<<i)){
        p+=w[i];
      }else{
        t&=w[i]=='A';
      }
    }
    if(!t)continue;
    if(s==p){
      cout << "YES" << endl;
      return 0;
    }
    
  }
  cout << "NO" << endl;
}