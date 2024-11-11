#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
long long a[N];
int len;
int main() {
  string s, temp;
  cin >> s >> temp >> len;
  int n = s.length(), c = 0;
  for (int i = 0; i < n; i++) {
    long long cnt = 0, h = 0;
    for (int k = i; k < n; k++) {
      if (temp[s[k] - 'a'] == '0') cnt++;
      if (cnt <= len) {
        h = (h * 131) + s[k];
        a[c++] = h;
      } else
        break;
    }
  }
  sort(a, a + c);
  cout << unique(a, a + c) - a << endl;
  return 0;
}
