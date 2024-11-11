#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;
int sub(const string& s, char c) {
  stringstream ss(c + s + c);
  int mx = 0;
  string buf;
  while(getline(ss, buf, c)) {
    mx = max(mx, (int)buf.size());
  }
  return mx;
}


int main() {
  string s;
  cin >> s;
  
  int mn = 1e9;
  for(char c = 'a'; c <= 'z'; ++c) {
    mn = min(mn, sub(s, c));
  }
  cout << mn << endl;
  return 0;
}
