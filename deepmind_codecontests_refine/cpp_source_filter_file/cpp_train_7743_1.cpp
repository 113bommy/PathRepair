#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  char x[n];
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    if (x[i] == '#') {
      cnt++;
    }
    if (cnt >= k) {
      cout << "no" << endl;
      return 0;
    }
    if (x[i] == '.') {
      cnt = 0;
    }
  }
  cout << "YES";
}
