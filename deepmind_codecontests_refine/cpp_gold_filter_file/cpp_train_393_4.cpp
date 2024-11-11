#include <bits/stdc++.h>

using namespace std;

int main(){
  string s;
  cin >> s;
  int cnt=0;
  int n=s.length();
  for(int i=0;i<n;i++){
    if(s[i]=='1'){
      cnt++;
    }
  }
  cout << min(cnt,n-cnt)*2 << endl;
}
