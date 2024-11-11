#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,ans = 0,h;
  cin >> n >> k;
  for(int i=0;i<n;i++){
    cin >> h;
    if(h >= k)ans++;
  }
  cout << ans << endl;
}
