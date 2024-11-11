#include <bits/stdc++.h>
using namespace std;
void test_case() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  bool inn = false;
  long long int ind = -1;
  for (int i = 0; i < n; i++) {
    if (i && i + 1 < n) {
      if (s[i] - 'a' >= s[i - 1] - 'a' && s[i + 1] - 'a' <= s[i] - 'a') {
        inn = true;
        ind = i;
        break;
      }
    } else if (!i) {
      if (s[i + 1] - 'a' < s[i] - 'a') {
        inn = true;
        ind = i;
        break;
      }
    }
  }
  if (inn) {
    for (int i = 0; i < n; i++) {
      if (ind == i) continue;
      cout << s[i];
    }
  } else
    s.pop_back(), cout << s;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long int t;
  t = 1;
  while (t--) {
    test_case();
  }
}
