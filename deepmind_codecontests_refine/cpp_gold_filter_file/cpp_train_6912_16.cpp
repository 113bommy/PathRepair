#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count = 0;
  string s;
  cin >> n >> s;
  for (int i = n; i < s.size(); i += n) {
    if (s[i - 1] == s[i - 2] && s[i - 1] == s[i - 3]) count++;
  }
  cout << count << endl;
}
