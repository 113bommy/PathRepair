#include<bits/stdc++.h>
using namespace std;

int alp[26]={0};
int main(){
  string w; cin>>w;

  for(int i=0;i<w.length();i++){
    alp[w[i]-'a']++;
  }
  for(int i=0;i<26;i++){
    if(alp[i]%2!=0){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}