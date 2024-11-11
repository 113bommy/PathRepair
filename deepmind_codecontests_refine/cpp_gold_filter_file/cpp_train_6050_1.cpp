#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int power(int x, int a, int b) {
  if (a <= 0) return (1);
  long long z = power(x, a / 2, b);
  z = (z * z) % b;
  if (a % 2) z = (z * x) % b;
  return (z);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int freq[26], n;
  memset(freq, 0, sizeof freq);
  string str;
  cin >> n;
  cin >> str;
  for (auto c : str) {
    freq[c - 'a']++;
  }
  int idx = 0;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < freq[i]; j++) {
      cout << (char)('a' + i) << "";
    }
  }
  cout << endl;
  return (0);
}
