#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count = 0;
  string t;
  cin >> n;
  cin >> t;
  std::size_t found = t.find("xxx");
  for (int i = 0; i < t.length() - 1; i++) {
    char e = t[i];
    if (found != std::string::npos && e == 'x' && t[i + 1] == 'x' &&
        t[i + 2] == 'x') {
      count++;
    }
  }
  cout << count;
  return 0;
}
