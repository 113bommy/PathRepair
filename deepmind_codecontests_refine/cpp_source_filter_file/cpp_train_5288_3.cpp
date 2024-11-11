#include<bits/stdc++.h>
using namespace std;
int main() {
  long long int f,n,r,p,s,k,ans = 0;
  string s1;
  cin >> n >> k >> r >> s >> p;
  cin >> s;
  for (int i =0; i < s1.size(); i++) {
    if (s1[i] == 'r') f = p;
    if (s1[i] == 'p') f = s;
    if (s1[i] == 's') f = r;
    if(i >= k && s1[i-k] == s1[i]){
      f = 0;
      s1[i] = '0';
    }
    ans += f;
    cout << ans << "\n";
   return 0;
}