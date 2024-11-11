#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, counter = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    set<char> ss;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] - '0' <= k) {
        ss.insert(s[j]);
      }
    }
    if (ss.size() == k + 1) {
      counter += 1;
    }
  }
  cout << counter << "\n";
  return 0;
}
