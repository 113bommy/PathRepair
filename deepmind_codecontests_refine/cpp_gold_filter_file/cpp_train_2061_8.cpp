#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  for(int i=1; i <= s.size(); i++){
    if((i%2==1 && s.at(i-1) == 'L') || (i%2==0 && s.at(i-1) == 'R')){
      cout<<"No";
      return 0;
    }
  }
    cout<<"Yes";
    return 0;
}