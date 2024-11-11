#include "bits/stdc++.h"
using namespace std;
const int INF = 1e9;

signed main(){
  int N; cin >> N;
  string s; cin >> s;
  int Q; cin >> Q;
  vector<set<int> > alp(26, set<int> {INF});
  for(int i = 0; i < N; i++) alp[s[i] - 'a'].insert(i);
  
  for(int i = 0; i < Q; i++){
    int t; cin >> t;
    if(t == 1){
      int i; char c; cin >> i >> c; --i;
	  if(s[i] != c) S[s[i] - 'a'].erase(i);
		s[i] = c;
		S[c-'a'].insert(i);
    }
    if(t == 2){
      int ans = 0;
      int l, r; cin >> l >> r; --l;
      for(int c = 0; c < 26; c++){
        if(alp[c].empty()) continue;
        if(*alp[c].lower_bound(l) < *alp[c].lower_bound(r)) ans++;
      }
      cout << ans << endl;
    }
  }
}
