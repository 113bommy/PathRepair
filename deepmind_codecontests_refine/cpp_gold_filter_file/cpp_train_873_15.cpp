#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, n, k, i, count = 0, temp = 0, c, j;
  cin >> n >> k;
  set<int> s;
  string str;
  for (i = 0; i < n; i++) {
    cin >> str;
    j = 0;
    while (j < str.size()) {
      x = str[j] - '0';
      if (x <= k) {
        s.insert(x);
      }
      j++;
    }
    if (s.size() == k + 1) count++;
    s.clear();
  }
  cout << count << endl;
  return 0;
}
