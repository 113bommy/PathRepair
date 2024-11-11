#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
  string s;
  int k;
  cin>>s>>k;

  map<string, bool> m;
  for(int i=0; i<s.length(); i++) {

    for(int j=1; j<=min(k, (int)s.length()-i); j++) {
      m[s.substr(i,j)] = true;
    }
  }


  for(auto x : m) {
    if(k==1) {
      cout<<x.first<<endl;
      break;
    }
    k--;
  }
}
