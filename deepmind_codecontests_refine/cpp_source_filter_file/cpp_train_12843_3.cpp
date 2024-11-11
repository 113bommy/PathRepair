#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> k;
  int count = 0;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    int luck_count = 0;
    for (int j = 0; j < s.size(); j++)
      if (s[j] == '4' || s[j] == '7') luck_count++;
    if (luck_count <= k) count++;
  }
  cout << count << endl;
  return 0;
}
