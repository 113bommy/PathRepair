#include<bits/stdc++.h>
using namespace std;
int main(){
  int a=0;string s;cin>>s;
  for(int i=0;i<4;i++){
    if(s.at(i)=='2')a++;
  }
  cout<<a<<endl;
}