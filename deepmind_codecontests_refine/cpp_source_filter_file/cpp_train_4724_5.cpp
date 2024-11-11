#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<int> r;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'l')
      r.push_back(i + 1);
    else
      printf("%d\n", i + 1);
  }
  for (int i = r.size() - 1; i >= 0; i--) {
    printf("%d\n", r[i] + 1);
  }
  return 0;
}
