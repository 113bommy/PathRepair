#include<bits/stdc++.h>
using namespace std;
int main(){
  ll a,b,v,w,t;
  cin >> a >> v >> b >> w >> t;
  if(t*abs(v-w) >= abs(a-b) && v >= w){
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
  return 0;
}
