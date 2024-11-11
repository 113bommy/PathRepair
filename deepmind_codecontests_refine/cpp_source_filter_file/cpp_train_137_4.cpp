#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[26];
  memset(arr, 0, sizeof(arr));
  int k;
  string s, alpha = "abcdefghijklkmnopqrstuvwxyz";
  string res = "";
  cin >> k >> s;
  for (int i = 0; i < s.size(); i++) {
    arr[s[i] - 'a']++;
  }
  for (int i = 0; i < alpha.size(); i++) {
    char c = alpha[i];
    if (arr[c - 'a'] % k) {
      cout << -1;
      return 0;
    }
    for (int j = 0; j < arr[c - 'a'] / k; j++) {
      res += c;
    }
  }
  for (int i = 0; i < k; i++) cout << res;
}
