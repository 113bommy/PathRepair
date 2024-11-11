#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.first < b.first) return true;
  return false;
}
int main() {
  string s;
  cin >> s;
  int count = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
      count++;
    else if ((s[i] >= '0' && s[i] <= '9') && (s[i] - '0') % 2 != 0)
      count++;
  }
  cout << count << endl;
}
