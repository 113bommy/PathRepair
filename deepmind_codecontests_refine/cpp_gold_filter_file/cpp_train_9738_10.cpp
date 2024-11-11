#include <bits/stdc++.h>
using namespace std;
vector<string> str;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a, b;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a')
      a.push_back(i + 1);
    else
      b.push_back(i + 1);
  }
  if (k >= a.size() || k >= b.size())
    cout << n << endl;
  else {
    int s, e, mx = 0;
    e = k;
    s = 0;
    mx = max(mx, a[e++] - 1);
    for (; e < a.size(); e++) mx = max(mx, a[e] - a[s++] - 1);
    mx = max(mx, n - a[s]);
    e = k;
    s = 0;
    mx = max(mx, b[e++] - 1);
    for (; e < b.size(); e++) mx = max(mx, b[e] - b[s++] - 1);
    mx = max(mx, n - b[s]);
    cout << mx << endl;
  }
  return 0;
}
