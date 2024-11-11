#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  int n;
  int w;
  cin >> n;
  cin >> w;
  string s;
  string s2;
  map<string, string> dec;
  for (int i = 0; i < w; i++) {
    cin >> s;
    cin >> s2;
    dec[s] = s2;
  }
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (dec[s].size() > s.size()) {
      cout << s << " ";
    } else {
      cout << dec[s] << " ";
    }
  }
  return 0;
}
