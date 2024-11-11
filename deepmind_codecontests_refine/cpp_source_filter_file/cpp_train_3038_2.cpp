#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int maxn = n * n - 1;
  int c = 0;
  for (int i = 0; i < maxn; i++) {
    if (i % 2 == 0) {
      cout << i << " ";
      c++;
    }
    if (c == n) {
      cout << endl;
      c = 0;
    }
  }
  for (int i = 0; i < maxn; i++) {
    if (i % 2 == 1) {
      cout << i << " ";
      c++;
    }
    if (c == n) {
      cout << endl;
      c = 0;
    }
  }
}
