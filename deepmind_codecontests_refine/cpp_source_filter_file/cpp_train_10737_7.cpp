#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  vector<int> len;
  bool el;
  el = a[0];
  int maxlen = 0;
  for (i = 0; i < n; i++) {
    if (el != a[i]) {
      len.push_back(maxlen);
      maxlen = 1;
      el = a[i];
    } else
      maxlen++;
  }
  len.push_back(maxlen);
  int maxel = -1;
  for (i = 0; i < len.size() - 1; i++)
    maxel = max(maxel, min(len[i], len[i + 1]));
  cout << maxel;
}
