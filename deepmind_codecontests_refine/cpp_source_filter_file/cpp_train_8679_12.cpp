#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int hash[3001] = {};
  int a;
  for (int i = 0; i < n + 1; i++) {
    cin >> a;
    hash[a]++;
  }
  for (int i = 1; i < 3001; i++) {
    if (hash[i] == 0) {
      cout << i << "\n";
      break;
    }
  }
}
