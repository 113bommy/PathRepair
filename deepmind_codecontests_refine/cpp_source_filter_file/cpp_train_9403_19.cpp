#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int k;
  cin >> k;
  vector<int> str;
  int s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    str.push_back(s);
  }
  s = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] >= str[k] && str[i] > 0) s++;
  }
  cout << s;
  return 0;
}
