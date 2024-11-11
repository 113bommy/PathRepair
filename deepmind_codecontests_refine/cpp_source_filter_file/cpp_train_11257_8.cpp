#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int a[26];
  for (int i = 0; i < 26; i++) {
    a[i] = 0;
  }
  int i = 1;
  int ans = 0;
  int x = 0;
  while (i <= n && x < 4) {
    i--;
    char c = s[i];
    int l = 0;
    while (i < n && s[i] == c) {
      i++;
      l++;
    }
    a[c - 97] += (l / k);
    i++;
    x++;
  }
  int max = 0;
  for (int i = 0; i < 26; i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }
  cout << max;
  return 0;
}
