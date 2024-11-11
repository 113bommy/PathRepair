#include<bits/stdc++.h>
using namespace std;
int main(){
  string o, e;
  cin >> e >> o;
  for(int i = 0; i < e.size(); i++){
    cout << e[i];
    if(i < o.size()) cout << o[i];
  }
  return 0;
}