#include <bits/stdc++.h>

using namespace std;
string s;
int MIN = 1000;
int main() {
  cin >> s;

  for(int i = 0; i < 26; i++) {
    string aa = s;
    string tmp(aa.size(),'a'+i);
    int ans = 0;
    while(true) {
      if(tmp == aa) break;

      for(int j = 0; j < aa.size(); j++) {
	if(aa[j+1] == 'a'+i) aa[j] = aa[j+1];
      }
      aa.pop_back();
      tmp.pop_back();
      ans++;
    }
    MIN = min(MIN,ans);
  }
  cout << MIN << endl;
}
			      
