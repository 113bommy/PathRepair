#include <bits/stdc++.h>
using namespace std;
 
int main(){
  string s;cin>>s;
  sort(s.begin(),s.end());
  cout << ((s[0]==s[1]&&s[2]==s[3]&&s[0]!=s[2]) ? "Yes" : "No") << endl;
}