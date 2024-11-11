#include<iostream>
#include<string>
using namespace std;

int main(){
  string s;
  cin>>s;
  int i,a=0,0;
  for(i;i<4;i++){
  if(s[i]=='+')a++;
  else a--;
  }
  cout<<a;
}




