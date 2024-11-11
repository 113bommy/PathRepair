#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;

int main(){
	int h, w, n;
  	cin >> h >> w >> n;
  	vector<int> hs(h), ws(w);
  	set<P> s;
  	rep(i, n){
    	int r, c;
      	cin >> r >> c;
      	r--; c--;
      	hs[r]++;
      	hw[c]++;
      	s.emplace(r, c);
    }
  
  	int mh = 0, mw = 0;
  	rep(i, h) mh = max(mh, hs[i]);
   	rep(j, w) mw = max(mw, ws[j]);
  	vector<int> is, js;
  	rep(i, h) if(mh == hs[i]) is.push_back(i);
  	rep(j, w) if(mw == hs[j]) js.push_back(j);
  	
  	int ans = mh+mw;
  	for(int i : is){
    	for(int j : js){
        	if(s.count(P(i, j))) continue;
          	cout << ans << endl;
          	return 0;
        }
    }
  	ans--;
  	cout << ans << endl;
}