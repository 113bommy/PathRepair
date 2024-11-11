#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int scnt=0,sum=0;
  for(int i=0;i<s.size();i++){
    if(scnt>0&&s[i]=='T'){
      scnt--;
      sum+=2;
    }
    if(s[i]=='S')scnt++;
  }
  cout<<s.size()-sum<<endl;
  return 0;
}
