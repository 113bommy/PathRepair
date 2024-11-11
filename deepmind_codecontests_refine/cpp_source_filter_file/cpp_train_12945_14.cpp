#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string str, str1, str2;
  long long i, u = 0, l = 0, n = 0, k;
  cin >> str;
  sort(str.begin(), str.end(), greater<char>());
  for (i = 0; i < str.length() - 1; i++) {
    if (str[i] != str[i + 1]) {
      cout << str[i];
      break;
    } else
      cout << str[i];
  }
  return 0;
}
