#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int count = 0;
  for (int i = 0; i < s.size() - 10; i++) {
    if (s[i] == '8') count++;
  }
  int l = n - 11;
  if (l / 2 < count)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
