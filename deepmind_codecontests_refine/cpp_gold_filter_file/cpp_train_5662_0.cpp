#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  string a, b;
  cin >> a >> b;
  if (a.length() != b.length()) {
    cout << "NO" << endl;
    return 0;
  }
  if (a == b) {
    cout << "YES" << endl;
    return 0;
  }
  int n = a.length();
  bool ans_a = 0;
  bool ans_b = 0;
  if (n == 1) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] == '1') {
      ans_a = true;
    }
    if (b[i] == '1') {
      ans_b = true;
    }
  }
  if (ans_a and ans_b) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
