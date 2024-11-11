#include <bits/stdc++.h>
using namespace std;
int main() {
  const static int MAX = 20000;
  int n;
  map<int, int> m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    m[x]++;
  }
  int res = 0;
  for (int i = 0; i <= 100; i++) {
    res += m[i] / 2;
  }
  cout << res / 2 << endl;
}
