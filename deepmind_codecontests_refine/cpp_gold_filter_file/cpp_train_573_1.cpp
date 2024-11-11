#include <bits/stdc++.h>
using namespace std;
void in_out_file() {}
int main() {
  in_out_file();
  long long int tc = 1;
  while (tc--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    bool flag = false;
    for (int i = 0; i < 5001; i++) {
      if (flag) break;
      for (int j = 0; j < 5001; j++) {
        if (a * i + b * j == c) {
          flag = true;
          break;
        }
        if (a * i + b * j > c) break;
      }
    }
    if (flag) {
      cout << "Yes"
           << "\n";
    } else {
      cout << "No"
           << "\n";
    }
  }
  return 0;
}
