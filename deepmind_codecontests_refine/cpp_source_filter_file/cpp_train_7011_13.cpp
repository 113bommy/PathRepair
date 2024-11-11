#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k = 0;
  cin >> n >> m;
  for (int i = -1000; i <= 1000; i++) {
    for (int j = -1000; j <= 1000; j++) {
      if (i * i + j == n && j * j + i == m) k++;
    }
  }
  cout << k;
}
