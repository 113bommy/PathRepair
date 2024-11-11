#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<long int, long int> &a,
               const pair<long int, long int> &b) {
  return (a.second < b.second);
}
int main() {
  long int n, m, i;
  cin >> n >> m;
  set<string> s;
  string s1;
  for (i = 0; i < n + m; i++) {
    cin >> s1;
    s.insert(s1);
  }
  i = n + m - s1.size();
  if (i % 2 == 0) {
    n = n - i;
    m = m - i;
    if (n > m) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  } else {
    n = n - i;
    m = m - i;
    m--;
    if (n > m) {
      cout << "YES";
    } else {
      cout << "NO";
    }
  }
  return 0;
}
