#include<bits/stdc++.h>
using namespace std;
int main(){
  set<string>s;
  int n;
  cin >> n;
  while(n--){
    string l;
    	cin >>l;
    s.insert(l);
  }
  cout << s.size();
}