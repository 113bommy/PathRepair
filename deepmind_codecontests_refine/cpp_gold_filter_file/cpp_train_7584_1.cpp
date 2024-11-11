#include<bits/stdc++.h>
using namespace std;

int main(void){
  string s[3];
  cin>>s[0]>>s[1]>>s[2];
  int p[3]={},q=0;
  while(p[q]!=s[q].size()){
    p[q]++;
    q=s[q][p[q]-1]-'a';
  }
  cout<<(char)('A'+q)<<endl;
}