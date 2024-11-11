#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n;
  int a[n];
  set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> x;
    s.insert(x);
  }
  if (s.size() > 3)
    cout << "NO";
  else if (s.size() < 3)
    cout << "YES";
  else {
    set<int>::iterator it;
    vector<int> v;
    for (it = s.begin(); it != s.end(); it++) v.push_back(*it);
    if (v[1] - v[0] == v[2] - v[1])
      cout << "YES";
    else
      cout << "NO";
  }
}
