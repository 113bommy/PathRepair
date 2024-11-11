#include <bits/stdc++.h>

using namespace std;

int main(){
 string s;
  cin >> s;
  
  int num[3]={0};
  for(int i=0;i<s.size();i++) num[s[i]-'a']++;

  if(max({num[0],num[1],num[2]})-min({num[0],num[1],num[2]})<=1) cout << "YES" << endl;
  else cout << "NO" << endl;
  
}
