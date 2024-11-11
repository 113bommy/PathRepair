#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j, mn;
  int freq[26] = {0};
  string s;
  cin >> n >> k;
  cin >> s;
  for (i = 0; i < s.length(); i++) {
    j = s[i] - 65;
    freq[j]++;
  }
  mn = 10000;
  for (i = 0; i < k; i++) {
    mn = min(mn, freq[i]);
  }
  cout << k * mn << "\n";
}
