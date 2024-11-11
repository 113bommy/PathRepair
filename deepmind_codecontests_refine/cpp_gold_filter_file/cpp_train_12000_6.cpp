#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> n2(50);
  n2[0] = 1;
  for (int i = 1; i < 50; i++) n2[i] = n2[i - 1] * 2;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i & 1)
        cout << "0 ";
      else
        cout << n2[i + j - 3] << " ";
    }
    cout << "\n";
  }
  cout.flush();
  int q;
  cin >> q;
  while (q--) {
    long long k;
    cin >> k;
    cout << "1 1\n";
    int i = 1, j = 1;
    int addi = 0;
    while (true) {
      addi = (i - 1) & 1;
      i += (addi ^ (k & 1));
      j += (1 ^ addi ^ (k & 1));
      cout << i << " " << j << "\n";
      k >>= 1;
      if (i == n || j == n) break;
    }
    while (j < n) {
      j++;
      cout << i << " " << j << "\n";
    }
    while (i < n) {
      i++;
      cout << i << " " << j << "\n";
    }
    cout.flush();
  }
  return 0;
}
