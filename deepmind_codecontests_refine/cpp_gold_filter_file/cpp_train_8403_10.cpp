#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  pair<int, int> a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a + n);
  string s;
  cin >> s;
  stack<int> ram;
  int k = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (s[i] == '0') {
      cout << a[k].second + 1 << " ";
      ram.push(a[k++].second);
    } else {
      cout << ram.top() + 1 << " ";
      ram.pop();
    }
  }
  return 0;
}
