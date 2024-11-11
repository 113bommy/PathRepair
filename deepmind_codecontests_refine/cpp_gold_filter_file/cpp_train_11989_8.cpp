#include <bits/stdc++.h>
using namespace std;
int main() {
  int freq[26], n, count = 0;
  string s;
  cin >> n;
  cin.ignore();
  for (int i = 0; i < 26; i++) freq[i] = 0;
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    freq[s[0] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (freq[i] <= 2) continue;
    int a = freq[i] / 2, b = freq[i] - a;
    count += ((a * (a - 1)) / 2 + (b * (b - 1)) / 2);
  }
  cout << count << endl;
  return 0;
}
