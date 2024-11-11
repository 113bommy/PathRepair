#include <bits/stdc++.h>
using namespace std;

int main (){
  int n;
  string s;
  cin >> n >> s;
  long long ans = 0;
  long long  r, g, b;
  int k;
  r = count(s.begin(), s.end(), 'R');
  g = count(s.begin(), s.end(), 'G');
  b = count(s.begin(), s.end(), 'B');
  ans = r * g * b;
  for(int j = 1; j < n; j++){
    for(int i = 0; i < j; i++){
      k = 2 * j - i;
      if(k < n){
	if(s[i] != s[j] && s[j] != s[k] && s[k] != s[i]) ans--;
      }
    }
  }
 
  cout << ans << endl;
}
