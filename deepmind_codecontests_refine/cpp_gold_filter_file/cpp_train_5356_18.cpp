#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, bool> hash;
  int p, n;
  bool has = false;
  cin >> p >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x %= p;
    if (hash.count(x) && !has) {
      cout << i + 1 << endl;
      has = true;
    } else {
      hash[x] = true;
    }
  }
  if (!has) printf("-1");
}
