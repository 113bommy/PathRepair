include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int ans = s.size();
	for (int i = 0; i < s.size(); i++) {
	  char c = s[i];
	  int cnt=0,temp=0;
	  for (int j = 0; j < s.size(); j++) {
	    if (s[s.size() - j - 1] != c) {
		  cnt++;
		}
        else {
		  cnt=0;
		}
		temp = max(temp, cnt);
	  }
	  ans = min(ans, temp);
	}
  cout << ans << endl;
}