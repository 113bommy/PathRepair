#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int ascii = 97;
  string res = "";
  for (size_t i = 0; i < k; i++) {
    res += (char)(ascii);
    ascii++;
  }
  if (res.length() < n) {
    for (size_t i = 0; i < n - k; i++) {
      res += res[i];
    }
  }
  cout << res << endl;
  return 0;
}
