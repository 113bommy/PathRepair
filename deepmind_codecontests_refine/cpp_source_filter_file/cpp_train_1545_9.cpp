#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  int value=0;
  cin >> a;
  map<string,int> mp;
  for(int i=0;i<a;i++){
    string t;  cin >>t;
    mp[t]++;
  }
  cin >>b;
  for(int i=0;i<b;i++){
    strin t; cin >>t;
    mp[t]--;
  }
  for(auto t:mp){
    value =max(max,t.second);
  }
  cout <<value <<endl;
}
