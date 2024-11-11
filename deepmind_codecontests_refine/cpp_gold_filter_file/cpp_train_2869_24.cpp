#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  string a;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    if (a.size() <= 10)
      cout << a << endl;
    else {
      cout << *a.begin() << a.size() - 2 << *(a.end() - 1) << endl;
    }
  }
  return 0;
}
