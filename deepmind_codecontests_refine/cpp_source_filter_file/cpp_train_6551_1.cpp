include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main(){
  int n,area[4];
  ll h;
  
  cin >> n;
  vector<ll> hs;
  ull ans = 0;
  area[0] = area[1] = area[2] = area[3] = 0;
  for(int i=0;i<n;i++){
    cin >> h;
    hs.push_back(h);
  }
  sort(hs.begin(),hs.end(),greater<ll>() );
  for(int i=0;i<n;i++){
    int pos = i%4;
    ans += hs[i]-area[pos]>=0?hs[i]-area[pos]:0;
    area[pos]++;
  }
  cout << ans+1 << endl;

return 0;
}