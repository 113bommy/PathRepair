#include <bits/stdc++.h>
using namespace std;
void chunk() {
  int n;
  cin >> n;
  string s, s1;
  cin >> s;
  int i = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      for (int j = s.size() - 1; j >= 0; j--) {
        if (s[j] == '0') {
          s.erase(s.begin() + i, s.begin() + j);
          break;
        }
      }
      break;
    }
  }
  cout << s << endl;
}
int main() {
  long long int n;
  cin >> n;
  for (int i = 1; i <= n; i++) chunk();
  return 0;
}
