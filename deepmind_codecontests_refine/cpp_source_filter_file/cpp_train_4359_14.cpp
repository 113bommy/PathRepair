#include <iostream>
#include <map>
using namespace std;

int main(){
  map<int,num> s;
  int a;
  for(int i=0;i<3;i++){
    cin>>a;
    s[a]=1;
  }
  cout<<s.size();
}