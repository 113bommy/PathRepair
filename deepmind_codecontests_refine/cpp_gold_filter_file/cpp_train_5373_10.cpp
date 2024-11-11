#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, int> cek;
  string s;
  cin >> s;
  int k;
  cin >> k;
  int total = 0;
  if (k <= s.length()) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] >= 'a' && s[i] <= 'z') {
        cek[s[i]]++;
      }
      if (cek[s[i]] == 1) count++;
    }
    cout << max(0, k - count) << endl;
  } else {
    cout << "impossible" << endl;
  }
}
