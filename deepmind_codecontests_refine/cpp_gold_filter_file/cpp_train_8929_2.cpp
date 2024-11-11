# include<bits/stdc++.h>
# define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
 
int main () {
  int n;
  map<string, int> mp;
  cin >> n;
  int ma = 0;
  rep(i, n) {
    string s;
    cin >> s;
    mp[s]++;
    ma = max(ma, mp[s]);
  }
  
  for (auto a : mp) if (a.second == ma) cout << a.first << endl;
  
  return 0;
}