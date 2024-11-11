#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  int t = 0;
  cin >> t;
  for (int k = 0; k < t; k++) {
    int n = 0;
    cin >> n;
    if (n == 1) {
      cout << 1 << " " << 1 << endl;
    } else if (n == 2) {
      cout << 1 << " " << 2 << endl;
    } else if (n == 3) {
      cout << 2 << " " << 2 << endl;
    } else if (n == 4) {
      cout << 2 << " " << 1 << endl;
    } else {
      long long int i = 1;
      while (i * i <= n) {
        i++;
      }
      int c = n - (i - 1) * (i - 1);
      if (c < i) {
        cout << c << " " << i << endl;
      } else if (c == i) {
        cout << i << " " << i << endl;
      } else {
        c = c - i;
        cout << i << " " << i - c << endl;
      }
    }
  }
}
