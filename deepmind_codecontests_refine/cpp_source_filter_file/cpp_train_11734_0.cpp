#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  char ch = 'a';
  long long sum = 0;
  while (sum <= k) {
    for (int i = 0; i < n && sum <= k; ++i) {
      if (s[i] == ch) {
        ++sum;
        s[i] = '.';
      }
    }
    ++ch;
  }
  for (char x : s)
    if (x != '.') cout << x;
  cout << endl;
  return 0;
}
