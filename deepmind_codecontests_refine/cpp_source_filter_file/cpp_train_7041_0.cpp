#include <bits/stdc++.h>
const int inf = 1000005;
using namespace std;
long long func(string &str) {
  int n = int((str).size());
  long long ans = 0LL;
  for (int i = 0; i < n; ++i) {
    int q = 0, s = 0;
    for (int j = i; j < n; ++j) {
      if (str[j] == '?')
        q++;
      else if (str[j] == '(')
        s++;
      else
        s--;
      if (s < 0) continue;
      if (q > s) q--, s++;
      if ((j - i + 1) % 2 == 0 && q >= s && s >= 0) {
        ans++;
      }
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str;
  cin >> str;
  cout << func(str) << "\n";
  return 0;
}
