#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool f = false;
  for (int i = 0; i < n; i++) {
    int64_t a;
    cin >> a;
    f |= a % 2 == 1;
  }
  cout << (f ? "first" : "second") << endl;
  return 0;
}
