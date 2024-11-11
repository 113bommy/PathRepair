#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main() {
  int n,a,ans=0;
  cin >> n;
  map<int,int> mp;
  for(int i=0; i<n; i++) {
    cin >> a;
    mp[a]++;
  }
  for(auto au:mp) {
    if(au.first<au.second) {
      ans+=au.second-au.first;
    }
    else if(au.first>au.second) {
      ans+=au.second;
    }
  }
  cout << ans << endl;
}