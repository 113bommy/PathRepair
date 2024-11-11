#include<bits/stdc++.h>
using namespace std;
int main(){
  string s1,s2="CODEFESTIVAL2016"
  cin >> s1;
  int x=0;
  for(int i=0;i<16;i++){
    if(s1[i]!=s2[i])x++;
  }
  cout<<x<<endl;
}
