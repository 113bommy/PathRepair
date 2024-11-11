#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  char a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int count[256] = {0};
  for (int i = 0; i < n; i++) count[a[i]]++;
  for (int i = 0; i < 256; i++) {
    if (count[i] > (k)) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
