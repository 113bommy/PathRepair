#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  string s,t;
  cin >> s >> t;
  for(int i=0;i<=n;i++){
    if(s.substr(i,s.size())==t.substr(0,t.size()-i)){
      cout << n+i;
      return 0;
    }
  }
}
