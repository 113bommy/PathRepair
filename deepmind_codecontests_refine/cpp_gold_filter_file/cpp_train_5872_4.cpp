#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  if (n == 3) {
    cout << ">.v\n...\n^.<\n";
    cout << "1 1\n";
    return 0;
  }
  if (n == 5) {
    cout << ">>>>v\n^v.<<\n^>>.v\n^v.<<\n^<<<<\n";
    cout << "1 1\n";
    return 0;
  }
  for (int i = 0; i + 1 < n; i++) cout << ">";
  cout << "v\n";
  for (int i = 1; i + 1 < n; i++) {
    if (i & 1) {
      cout << "^v";
      for (int j = 2; j < n; j++) {
        if (j * 3 / 2 < n - 1) {
          cout << ".<";
          j++;
        } else
          cout << "<";
      }
      cout << "\n";
    } else {
      cout << "^";
      for (int j = 2; j < n; j++) {
        if ((n - j + 1) * 3 / 2 < n - 1) {
          cout << ">.";
          j++;
        } else
          cout << ">";
      }
      cout << "v";
      cout << "\n";
    }
  }
  cout << "^";
  for (int i = 1; i < n; i++) cout << "<";
  cout << "\n";
  cout << "1 1\n";
  return 0;
}
