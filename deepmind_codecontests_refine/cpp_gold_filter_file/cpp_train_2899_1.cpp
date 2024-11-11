#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int cnt=0,mc=0,mi=1000;
  for(int i=0;i<s.size();i++){
    for(int j=0;j<s.size();j++){
      if(s[i]==s[j]){
        mc=max(mc,cnt);
        cnt=0;
      }else{
        cnt++;
      }
    }
    mc=max(mc,cnt);
    cnt=0;
    mi=min(mc,mi);
    mc=0;
  }
  cout<<mi<<endl;
}