#include <bits/stdc++.h>
using namespace std;
int main() {
  int c[100];
  for (int a = 0; a < 100; a++) c[a] = 0;
  string s;
  cin >> s;
  long long k = 0;
  for (int a = 0; a < s.length(); a++) {
    if (s[a] > 96) {
      c[s[a] - 86]++;
    } else {
      c[s[a] - 48]++;
    }
  }
  for (int a = 0; a < 100; a++) k += c[a] * c[a];
  cout << k;
  return 0;
}
