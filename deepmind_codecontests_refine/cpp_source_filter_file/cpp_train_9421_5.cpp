#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
const int INF = 1e9 + 9;
int r[100], c[100];
int main() {
  int n;
  cin >> n;
  int a, b;
  for (int i = 0; i < n * n; i++) {
    cin >> a >> b;
    if (!r[a] && !r[b]) {
      cout << i + 1 << endl;
      r[a] = 1;
      r[b] = 1;
    }
  }
  return 0;
}
