#include<bits/stdc++.h
using namespace std;
using ll = int64_t;
int main(){
  ll n, c, k; 
  cin >> n >> c >> k;
  ll t[n];
  for(ll i = 0; i < n; i++) cin >> t[i];
  sort(t, t + n);
  ll ans = 0, num = 1, s = t[0];
  for(ll i = 1; i < n; i++){
    if(t[i] > s + k || num == c){
      num = 0;
      ans++;
      s = t[i];
    }
    num++;
  }
  cout << ++ans << endl;
  return 0;
}