#include <bits/stdc++.h>
using namespace std;
char buff[200100];
int main() {
  long long n;
  cin >> buff;
  map<char, char> o;
  set<char> in;
  o['R'] = 'D';
  o['D'] = 'U';
  o['L'] = 'R';
  o['R'] = 'L';
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (in.find(o[buff[i]]) != in.end()) {
      ans++;
      in.clear();
    }
    in.insert(buff[i]);
  }
  if (in.size() > 0) ans++;
  cout << ans;
  return 0;
}
