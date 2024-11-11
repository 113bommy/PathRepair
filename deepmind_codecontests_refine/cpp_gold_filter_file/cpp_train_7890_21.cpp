#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  string s;
  cin >> n >> s >> k;
  k--;
  for(int i = 0; i < n; i++){
    s[i] = (s[i] == s[k] ? s[i] : '*');
  }
  cout << s << endl;
}
