#include <bits/stdc++.h>
using namespace std;
long long int sum;
int n, k, MAXS;
string str;
int s[26];
int main(void) {
  cin >> str;
  cin >> k;
  n = str.length();
  string alpha = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < 26; i++) {
    cin >> s[i];
    MAXS = max(MAXS, s[i]);
  }
  char c[3];
  for (int i = 0; i < n; i++) {
    str.copy(c, 1, i);
    sum = sum + s[alpha.find(c[0], 0)] * (i + 1);
  }
  for (int i = n + 1; i <= n + k; i++) sum = sum + MAXS * i;
  cout << sum;
}
