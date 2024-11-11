#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, c;
  cin >> a;
  vector<int> b(a);
  for (int i = 0; i < a; i++) {
    cin >> b[i];
  }
  c = 0;
  for (int i = 1; i < a - 1; i++) {
    if (b[i] > b[i - 1] && b[i] > b[i + 1] ||
        (b[i] < b[i - 1] && b[i] < b[i + 1])) {
      c += 1;
    }
  }
  cout << c;
  return 0;
}
