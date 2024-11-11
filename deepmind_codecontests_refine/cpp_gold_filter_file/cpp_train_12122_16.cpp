#include <bits/stdc++.h>
using namespace std;
int lmps[100];
int main() {
  int num, n, z;
  cin >> num >> n;
  for (int x = 1; x <= n; x++) {
    cin >> z;
    for (int i = z - 1; i < num && lmps[i] == 0; i++) {
      lmps[i] = z;
    }
  }
  for (int i = 0; i < num; i++) {
    cout << lmps[i] << " ";
  }
  return 0;
}
