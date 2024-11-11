#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (2 * k < n || 2 * k < m) return cout << "Second", 0;
  cout << "First";
}
