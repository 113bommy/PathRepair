#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
 
int main(){
  int N;
  cin>>N;
  string s;
  cin>>s;
  if(2*count(s.begin(),s.end(),"R")>s.size()) cout<<"Yes";
  else cout<<"No";
  return 0;
}
