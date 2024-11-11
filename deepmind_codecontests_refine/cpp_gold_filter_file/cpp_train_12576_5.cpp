#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
  lint N; cin >> N;
  lint ans = 0, ca = 0, cb = 0, cab = 0;
  for(lint i = 0; i < N; i++){
    string s; cin >> s;
    for(lint i = 1; i < s.size(); i++){
      if(s[i - 1] == 'A' && s[i] == 'B') ans++;
    }
    if(s[0] == 'B') cb++;
    if(s[s.size() - 1] == 'A') ca++;
    if(s[0] == 'B' && s[s.size() - 1] == 'A') cab++;
  }
  if(cab == ca && cab == cb && cab != 0) ans--;
  ans += min(ca, cb);
  cout << ans << endl;
}
