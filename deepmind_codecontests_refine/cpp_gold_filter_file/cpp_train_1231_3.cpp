#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, h; cin >> n >> h;
  vector<int> p; int best = 0;
  for(int i = 0; i < n; i++){
    int x, y; cin >> x >> y; best = max(best, x);
    p.push_back(y);
  }
  int ans = (h + best - 1) / best;
  sort(p.rbegin(), p.rend());
  for(int i = 0; i < n; i++){
  	h -= p[i]; h = max(h, 0);
    ans = min(ans, i + 1 + (h + best - 1) / best);
  }
  cout << ans << endl;
  return 0;
}
  
