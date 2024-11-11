#incldue <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  map<char,ll> mp;
  for(auto e : s) mp[e]++;
  if(mp.size() == 2 && mp[s[0]] == 2) cout << "Yes" << endl;
  else cout << "No" << endl;
}