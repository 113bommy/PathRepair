#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a;
  int inp;
  for (int i = 0; i < n; i++) {
    cin >> inp;
    a.push_back(inp);
  }
  for (int i = 0; i < n - 1; i++) {
    if ((a[i + 1] - a[i]) % 2 != 0) {
      if (((a[2] - a[1]) % 2 == 0) && i == 0) {
        cout << i + 1;
        break;
      }
      cout << i + 2;
      break;
    }
  }
}
