#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d\n", &n);
  set<string> q;
  string s;
  string ss;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    cin >> ss;
    s += ss;
    q.insert(s);
  }
  cout << (int)q.size();
  return 0;
}
