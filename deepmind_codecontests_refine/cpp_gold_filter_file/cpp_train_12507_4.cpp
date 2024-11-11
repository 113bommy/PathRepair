#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r[11000];
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l >> r[i];
  }
  int k, t = 0;
  cin >> k;
  for (int i = 0; i < n; i++) {
    if (r[i] >= k) {
      t++;
    }
  }
  cout << t;
}
