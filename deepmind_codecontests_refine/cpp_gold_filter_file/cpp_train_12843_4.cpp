#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int count = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int t = 0;
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == '4' || s[j] == '7') {
        t++;
      }
    }
    if (t <= k) count++;
  }
  cout << count << endl;
}
