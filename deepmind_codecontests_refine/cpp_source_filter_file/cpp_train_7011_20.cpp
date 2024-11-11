#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int count = 0;
  for (int i = 0; i < max(n, m); i++) {
    for (int j = 0; j < max(n, m); j++) {
      if (i * i + j == n && j * j + i == m) count++;
    }
  }
  cout << count;
}
