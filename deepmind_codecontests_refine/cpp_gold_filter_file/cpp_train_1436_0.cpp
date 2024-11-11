#include <bits/stdc++.h> 
using namespace std;
int main(void){
  int n; cin >> n;
  string s[n]; 
  int t[n];
  for(int i = 0; i< n; i++){
    cin >> s[i] >> t[i];
  }
  string x; cin >> x;
  int time;
  for(int i = 0; i<n; i++){
    if(s[i] == x) time = i;
  }
  int ans = 0;
  for(int i = time + 1; i < n; i++){
    ans += t[i];
  }
  cout << ans << endl;
}