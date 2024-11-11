#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < 30; i++) {
    s.insert(i * (i + 1) / 2);
  }
  if (s.find(n) == s.end())
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
