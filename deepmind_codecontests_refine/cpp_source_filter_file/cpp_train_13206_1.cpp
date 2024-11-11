#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int cnt=0;
  for(int i=0;i<s.size()-1;i++){
    if(a[i]!=a[i+1]){
      cnt++;
    }
  }
  cout << cnt << endl;
}