#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
  const int MAX = 100002;
  int n, a, b;
  int dp[MAX+1] = {};
  
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a >> b;
    dp[a] ++;
    dp[b+1] --;
  }
 
  for(int i=0; i<MAX; i++) {
    dp[i+1] += dp[i];
  }
  
  int mx = 0;
  for(int i=0; i<MAX; i++) {
    if(dp[i]+1>=i) mx = i-1;
  }
  cout << mx << endl;
   
  return 0;
}