#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, j;
  string h = "I hate ";
  string l = "I love ";
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (i % 2 != 0) {
      cout << h;
      if (i == n) {
        cout << "it ";
      } else {
        cout << "that ";
      }
    } else {
      cout << l;
      if (i == n) {
        cout << "it ";
      } else {
        cout << "that ";
      }
    }
  }
}
