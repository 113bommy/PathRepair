#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const long long mod = 1e9 + 7;
int n, i, j, k, l, m;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  for (i = 1; i < s1.size(); i++) {
    if (s1[i] >= s2[0]) {
      break;
    }
  }
  for (j = 0; j < i; j++) {
    cout << s1[j];
  }
  cout << s2[0];
}
