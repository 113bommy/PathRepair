#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, max = 0;
  cin >> n;
  map<int, int> m;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]]++;
  }
  map<int, int>::iterator it;
  for (it = m.begin(); it != m.end(); it++) {
    if (max < it->second) max = it->second;
  }
  if (max <= n - max + 1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
