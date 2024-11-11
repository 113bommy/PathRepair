#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int count = 0;
  for (int i = 1; i * i <= n; i++) {
    int p = n - (i * i);
    if (p * p + i == m) count++;
  }
  cout << count;
}
