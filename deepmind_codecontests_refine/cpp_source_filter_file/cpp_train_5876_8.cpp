#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  int cnt = 0;
  reverse(b.begin(), b.end());
  for (int i = 1; i <= a.size(); i++) {
    if (a[i] == b[i]) {
      cnt++;
    }
  }
  if (cnt == a.size()) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
