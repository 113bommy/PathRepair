#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define llint long long
#define mod 1000000007

using namespace std;

llint n;
vector<pair<llint, llint> > vec;

int main(void)
{
  cin >> n;
  llint x;
  for(int i = 1; i <= n; i++){
    cin >> x;
    vec.push_back(make_pair(x, 1));
  }
   for(int i = 1; i <= n; i++){
    cin >> x;
    vec.push_back(make_pair(x, 2));
  }
  sort(vec.begin(), vec.end());
  
  llint cnt = 0, cnt2 = 0, ans = 0;
  for(int i = 0; i < vec.size(); i++){
    if(vec[i].second == 1){
      if(cnt2 == 0) cnt1++;
      else ans *= cnt2, ans %= mod, cnt2--;
    }
    else{
      if(cnt1 == 0) cnt2++;
      else ans *= cnt1, ans %= mod, cnt1--;
    }
  }
  cout << ans << endl;
  return 0;
}