#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) {
  if (a > b) {
    return b;
  } else {
    return a;
  }
}
int main() {
  int oddKey, evenKey, oddChest, evenChest;
  int n, m;
  oddKey = 0;
  evenKey = 0;
  oddChest = 0;
  evenChest = 0;
  cin >> n;
  cin >> m;
  int chest[n];
  int key[m];
  for (int i = 0; i <= n - 1; i++) {
    cin >> chest[i];
    if (chest[i] % 2 == 0) {
      evenChest++;
    } else {
      oddChest++;
    }
  }
  for (int i = 0; i <= m - 1; i++) {
    cin >> key[i];
    if (key[i] % 2 == 0) {
      evenKey++;
    } else {
      oddKey++;
    }
  }
  cout << min(oddKey, evenChest) + min(evenKey, oddChest) << endl;
  return 0;
}
