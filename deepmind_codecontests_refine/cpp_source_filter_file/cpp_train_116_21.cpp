#include <bits/stdc++.h>
using namespace std;
int main() {
  string pal;
  long n;
  cin >> n;
  cin >> pal;
  for (long i = 1; i < n; i++) {
    if (pal[i] - pal[i - 1] < 0) {
      cout << "YES" << endl;
      cout << i - 1 << " " << i << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
