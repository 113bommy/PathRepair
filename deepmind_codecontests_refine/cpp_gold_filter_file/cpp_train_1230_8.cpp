#include<iostream>
#include<string>
using namespace std;

int main(){
  string s;
  cin>>s;
  int i=0,a=0;
  for(i;i<4;i++){
  if(s[i]=='+')a++;
  else a--;
  }
  cout<<a;
}






