#include <bits/stdc++.h>
const int Inf = 2 * 1000 * 1000 * 1000;
long long LINF = (long long)4e18;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  string s, s1;
  cin >> s;
  s1 = s;
  for (int i = k; i < n; i++) {
    s1[i] = s1[i - k];
  }
  if (s1 >= s) {
    cout << s1.size() << '\n' << s1;
    return 0;
  }
  for (int i = k - 1; i >= 0; --i) {
    if (s[i] != '9') {
      s1[i]++;
      break;
    } else {
      s1[i] = '0';
    }
  }
  for (int i = k; i < n; i++) {
    s1[i] = s1[i - k];
  }
  cout << s1.size() << '\n' << s1;
  return 0;
}
