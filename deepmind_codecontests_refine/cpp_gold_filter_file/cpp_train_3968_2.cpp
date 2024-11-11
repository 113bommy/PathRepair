#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> freq;
int cntrArr[27];
int main() {
  int n;
  cin >> n;
  string str;
  int mask, mask2;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    cin >> str;
    memset(cntrArr, 0, sizeof cntrArr);
    for (char c : str) {
      cntrArr[c - 'a']++;
    }
    mask = 0;
    for (int j = 0; j < 26; j++) {
      if (cntrArr[j] % 2) mask = mask | (1 << j);
    }
    res += freq[mask];
    for (int j = 0; j < 26; j++) {
      mask2 = mask;
      mask2 ^= (1 << j);
      res += freq[mask2];
    }
    freq[mask]++;
  }
  cout << res;
}
