#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a = 20, b = 20;
  bitset<100> con;
  int x, one = 10;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x < a) a = x;
    con[x] = true;
  }
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x < b) b = x;
    if (con[x]) {
      if (x < one) one = x;
    }
  }
  if (one != 10)
    cout << one << endl;
  else
    cout << min(a, b) << max(a, b) << endl;
}
