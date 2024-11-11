#include <bits/stdc++.h>
using namespace std;


int main(){
  string S;
  cin >> S;
  set<char> T;
  for(auto& s : S){
    T.insert(s);
  }
  cout << (S.size() == T.size() ? "yes" : "no") << endl;
  return 0;
}