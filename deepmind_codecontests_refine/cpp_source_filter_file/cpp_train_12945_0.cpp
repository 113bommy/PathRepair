#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  map<char, int> a;
  char ans;
  for (int i = 0; i < str.size(); i++) {
    ans = max(ans, str[i]);
    a[str[i]]++;
  }
  for (int j = 0; j < a[ans]; j++) {
    cout << ans;
  }
  cout << endl;
  return 0;
}
