#include <iostream>
#include <string>
using namespace std;

int solve(string s){
  int joi=0,ioi=0;
  for(int i=0;i<s.size()-2;i++){
    if(s.substr(i,3)=="JOI")joi++;
    else if(s.substr(i,3)=="IOI")ioi++;
  }
  cout<<joi<<endl;
  cout<<ioi<<endl;
  return 0;
}

int main(){
  string s;
  while(cin>>s){
    solve(s);
  }
  return 0;
}