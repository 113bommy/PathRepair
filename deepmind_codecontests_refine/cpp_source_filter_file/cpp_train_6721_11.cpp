#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans = 0;
  vector<char> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  if (a[0] == '>' && a[a.size() - 1] == '<')
    cout << 0;
  else {
    int i = 0;
    while (i < a.size()) {
      if (a[i] == '<') {
        ++ans;
        ++i;
      } else
        break;
    }
    i = a.size() - 1;
    while (i >= 0) {
      if (a[i] == '>') {
        ++ans;
        --i;
      } else
        break;
    }
  }
  cout << ans;
  return 0;
}
