#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  if (n == 1) {
    int a;
    cin >> a;
    if (a == 1)
      cout << "YES";
    else
      cout << "NO";
  } else {
    int count = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a == 0) count++;
    }
    if (count == 1)
      cout << "YES";
    else
      cout << "NO";
  }
  return 0;
}
