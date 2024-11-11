#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  set<char> set;
  while (n--) {
    char c;
    cin >> c;
    set.insert(c);
  }
  if (set.size() == 26)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
