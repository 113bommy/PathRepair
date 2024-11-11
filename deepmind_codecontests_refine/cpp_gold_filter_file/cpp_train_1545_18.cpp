#include <bits/stdc++.h>
using namespace std;

string s[110],t[110];
int main(){
 int n,m;
 cin >> n;
 for (int i=0;i<n;i++) cin >> s[i];
 cin >> m;
 for (int i=0;i<m;i++) cin >> t[i];
 
 int ans=0;
 for (int i=0;i<n;i++){
   int score = 0;
   for (int j=0;j<n;j++) if(s[j]==s[i]) score++;
   for (int j=0;j<m;j++) if(t[j]==s[i]) score--;
   ans = max(ans, score);
 }
  cout << ans << endl;
}
  
