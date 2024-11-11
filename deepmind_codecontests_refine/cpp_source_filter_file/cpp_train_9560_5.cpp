#include<bits/stdc++>
using namespace std;

int main(){
  int a,b,ans=0;
  cin >> a >> b;
  for(i=a;i<=b;i++){
    string s=to_string(i);
    if(s[0]==s[4] && s[1]==s[3])ans++;    
  }
  cout << ans << endl;
}