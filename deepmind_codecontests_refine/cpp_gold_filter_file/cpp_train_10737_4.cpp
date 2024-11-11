#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
int main() {
  int n, j = 0, c = 1;
  cin >> n;
  int a[n];
  cin >> a[0];
  vector<int> s;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    if (a[i] == a[i - 1])
      c++;
    else {
      s.push_back(c);
      c = 1;
    }
  }
  s.push_back(c);
  int max = min(s[0], s[1]);
  for (int i = 1; i < s.size() - 1; i++) {
    if (max < (min(s[i], s[i + 1]))) max = min(s[i], s[i + 1]);
  }
  cout << 2 * max;
  return 0;
}
