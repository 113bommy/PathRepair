#include <bits/stdc++.h>
const int64_t INF = 1000000000000000000;
using namespace std;
int main() {
  int64_t n, k;
  cin >> n >> k;
  string s[n];
  for (int i = 0; i < n - k + 1; i++) {
    cin >> s[i];
  }
  string names[51];
  for (int i = 0; i < 26; i++) {
    names[i] = (char)(i + 65);
  }
  for (int i = 26; i < 51; i++) {
    names[i] = names[i - 26] + (char)(i + 97);
  }
  for (int i = n - k; i >= 0; i--) {
    if (s[i] == "NO") {
      names[i] = names[i + k - 1];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << names[i] << " ";
  }
  return 0;
}
