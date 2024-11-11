#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string s1;
  for (int i = 0; i < n; i++) {
    s1 += s[i % k];
  }
  if (s1 >= s) {
    cout << n << endl;
    cout << s1 << endl;
  } else {
    int i;
    for (i = k - 1; i >= 0; i--) {
      if (s1[i] != '9') {
        break;
      } else {
        s1[i] = 0;
      }
    }
    s1[i]++;
    for (int i = 0; i < n; i++) {
      s1[i] = s1[i % k];
    }
    cout << n << endl;
    cout << s1 << endl;
  }
  return 0;
}
