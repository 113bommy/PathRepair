#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int k;
  cin >> k;
  if (k < 25) {
    cout << -1;
  } else {
    string result = "";
    int n = 5;
    for (; n <= 10000; n++) {
      if (k % n == 0) break;
    }
    int m = k / n;
    if (m < 5) {
      cout << -1;
      return 0;
    }
    string line = "aeiou";
    for (int i = 5; i < n; i++) {
      int c = i % 26;
      line += 'a' + c;
    }
    for (int i = 0; i < m; i++) {
      result += line;
      line =
          line.substr(line.length() - 1, 1) + line.substr(0, line.length() - 1);
    }
    cout << result;
  }
  return 0;
}
