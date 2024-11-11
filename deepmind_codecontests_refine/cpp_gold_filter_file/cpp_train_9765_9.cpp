#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int n; cin >> n;
  map<string,ll> mp;
  for(int i=0;i<n;i++){
    string s; cin >> s;
    sort(s.begin(),s.end());
    mp[s]++;
  }
  ll res=0;
  for(auto v : mp){
    if(v.second!=1)res+=v.second*(v.second-1)/2;
  }
  cout << res << endl;
}
