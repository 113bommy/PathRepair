#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string str;
  cin >> n;
  cin >> str;
  for (int i = 0; i < n - 1; i++) {
    if (str[i] > str[i + 1]) {
      cout << "YES" << endl << i + 1 << " " << i + 2 << endl;
      break;
    }
  }
  cout << "NO" << endl;
  return 0;
}
