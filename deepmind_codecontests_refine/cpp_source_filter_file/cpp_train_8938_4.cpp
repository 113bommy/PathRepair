#include <iostream>
#include <string>
using namespace std;

int main(){
  string s;
  int k;
  while(cin>>s){
    k=0;
    s='1'+s;
    if(s[1]==s[2]&&s[2]==s[3]&&k[1]!='s')k=1;
    else if(s[4]==s[5]&&s[5]==s[6]&&k[4]!='s')k=4;
    else if(s[7]==s[8]&&s[8]==s[9]&&k[7]!='s')k=7;
    else if(s[1]==s[4]&&s[4]==s[7]&&k[1]!='s')k=1;
    else if(s[2]==s[5]&&s[5]==s[8]&&k[2]!='s')k=2;
    else if(s[3]==s[6]&&s[6]==s[9]&&k[3]!='s')k=3;
    else if(s[1]==s[5]&&s[5]==s[9]&&k[1]!='s')k=1;
    else if(s[3]==s[5]&&s[5]==s[7]&&k[3]!='s')k=3;

    if(k==0)cout<<'d'<<endl;
    else cout<<s[k]<<endl;

  }
  return 0;
}