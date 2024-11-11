#include <bits/stdc++.h>
using namespace std;
int main() {
  deque<long long> q;
  int n;
  string s;
  cin >> s;
  n = s.size();
  bool f = 1;
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - 1 - i]) f = 0;
  }
  if (!f)
    cout << n << endl;
  else {
    for (int i = 1; i < n; i++)
      if (s[i - 1] != s[i]) f = 0;
    if (!f)
      cout << n - 1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
