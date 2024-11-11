#include <bits/stdc++.h>
using namespace std;
int a[1000], b[1000];
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      cout << "rated";
      return 0;
    }
  }
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) {
      cout << "unrated";
      return 0;
    }
  }
  cout << "maybe";
  return 0;
}
