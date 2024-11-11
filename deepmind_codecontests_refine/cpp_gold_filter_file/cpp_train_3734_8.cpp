#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
  string w;
  cin>>w;
  map<char,int>mp;
  for(const auto c : w){
    ++mp[c];
  }
  for(const auto e : mp){
    if(e.second%2==1){
      puts("No");
      return 0;
    }
  }
  puts("Yes");
}
    
