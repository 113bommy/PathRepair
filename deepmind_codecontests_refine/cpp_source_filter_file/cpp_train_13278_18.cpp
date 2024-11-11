#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    if (n % 2 != 0) {
      cout << "I love ";
    } else {
      cout << "I hate ";
    }
    if (n != 0) {
      cout << "that ";
    }
  }
  cout << "it";
  return 0;
}
