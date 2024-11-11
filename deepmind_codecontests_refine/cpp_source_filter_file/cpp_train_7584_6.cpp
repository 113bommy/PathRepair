#include<bits/stdc++.h>
using namespace std;
int main(){
  string s[3];
  cin>>s[0]>>s[1]>>s[2];
  int turn=0;
  char ans;
  while(1){
    if(s[turn].empty()){
      ans=turn+'A';
      break;
    }
    int tmp=s[turn][0]-'a'
    s[turn].erase(s[turn].begin());
    turn=tmp;
  }
  cout<<ans<<endl;
}
