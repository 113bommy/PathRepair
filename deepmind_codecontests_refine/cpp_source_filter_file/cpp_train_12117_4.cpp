#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, bool> t;
queue<int> q;
int main() {
  int len;
  cin >> len;
  for (int i = 1; i <= len; i++) {
    int a, b;
    cin >> a >> b;
    if (t[make_pair(a + b, -b)]) {
      cout << "YES";
      return 0;
    }
    t[make_pair(a, a + b)] = true;
  }
  cout << "NO";
}
