#include <bits/stdc++.h>
using namespace std;
int main() {
  string s_n;
  string s_m;
  cin >> s_n >> s_m;
  for (int i = 0; i < s_n.size(); i++) {
    if (s_n[i] == s_m[i]) {
      s_n[i] = '0';
    } else {
      s_n[i] = '1';
    }
  }
  for (int i = 0; i < s_n.size(); i++) {
    cout << s_n[i];
  }
}
