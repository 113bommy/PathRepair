#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int cnt=0,c=0,mi=10000;
  for(int i=0;i<s.size();i++){
    for(int j=0;j<s.size();j++){
      if(s[i]==s[j]){
        c=max(c,cnt);
        cnt=0;
      }else{
        cnt++;
      }
    }
    c=max(c,cnt);
    cnt=0;
    mi=min(c,mi);
    c=0;
  }
  cout<<mi<<endl;
}
